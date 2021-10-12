/*
   Created by plus on 7/20/21.
*/
#include <math.h>
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "segwayrmp/robot.h"

#include <stdio.h>
#include <stdlib.h>
 
#define TTY_PATH            "/dev/tty"
#define STTY_US             "stty raw -echo -F "
#define STTY_DEF            "stty -raw echo -F "
//#define STTY_US		"stty raw -echo"
//#define STTY_DEF        "stty -raw echo"

using namespace std;

namespace {
    enum TestCase {
        circleleft = 'a',
        circleright = 'd',
        stop = 'q',
        forward = 'w',
        backward = 's',
        Increase_max_speed = 'u',
        Decrease_max_speed = 'i',
        Increase_linear_speed = 'j',
        Decrease_linear_speed = 'k',
        Increase_angular_speed = 'n',
        Decrease_angular_speed = 'm'
    };


    /*******************************************************************************************/
    int get_char();
 
    int get_char()
    {
        fd_set rfds;
        struct timeval tv;
        char ch = 0;
 
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        tv.tv_sec = 0;
        tv.tv_usec = 1000000000000; //设置等待超时时间
 
        //检测键盘是否有输入
        if (select(1, &rfds, NULL, NULL, &tv) > 0){
            ch = getchar(); 
        }
        return ch;
    }
    /*****************************************************************************************/

    int rate = 100;
    char select_key = 'p';
    float current_angular = 0.1;
    float current_vel = 0.01;
    static float cur_time = 0;
    geometry_msgs::Twist cmd_vel;
    // segway_msgs::motor_enable cmd_enable;
    ros::ServiceServer chassis_send_event_srv_server;
    
    ros::ServiceClient ros_get_charge_mos_ctrl_status_cmd_client;
    segway_msgs::ros_get_charge_mos_ctrl_status_cmd ros_get_charge_mos_ctrl_status_srv;

    ros::ServiceClient ros_set_charge_mos_ctrl_cmd_client;
    segway_msgs::ros_set_charge_mos_ctrl_cmd ros_set_charge_mos_ctrl_srv;

    ros::ServiceClient ros_set_chassis_enable_cmd_client;
    segway_msgs::ros_set_chassis_enable_cmd ros_set_chassis_enable_srv;

    ros::ServiceClient ros_set_vel_max_cmd_client;
    segway_msgs::ros_set_vel_max_cmd ros_set_vel_max_cmd_srv;

    // iapActionClient ac("ros_set_iap_cmd_action", true);
    segway_msgs::ros_set_iap_cmdGoal ros_set_iap_cmd_goal;

    bool setChassisEnable(bool enable)
    {
        ros_set_chassis_enable_srv.request.ros_set_chassis_enable_cmd = enable;
        return ros_set_chassis_enable_cmd_client.call(ros_set_chassis_enable_srv);
    }

    void showHelp() {
        cout << endl << endl << endl;
        cout << "=====================================" << endl;
        cout << "    Chassis Keyboard Control Tool    " << endl;
        cout << "=====================================" << endl;
        cout << "w/s: Move forward/backward." << endl;
        cout << "a/d: Turn left/right." << endl;
        cout << "q: force stop" << endl;
        cout << "u/i: Increase/Decrease max speed by 10%." << endl;
        cout << "j/k: Increase/Decrease only linear speed by 10%" << endl;
        cout << "n/m: Increase/Decrease only angular speed by 10%" << endl;
        cout << "0: Exit" << endl;
        cout << "==========================================" << endl;
    }
    
    void ChassisControl(char& select_key) { 
        select_key = get_char();
        if (select_key==3){
            system(STTY_DEF TTY_PATH);
	    //cout<<"ctrl C1111111111111111111";
            return;
        }
        // cin >> select_key;
        // cout << "++" << select_key;
        cur_time = 0;
        if (select_key == 0) {
            cout << "shutdown!" << endl;
            ros::shutdown();
        }
        else
        {
            if (setChassisEnable(true))
            {
                ROS_INFO("ROS call ros_set_chassis_enable_srv success! res[%d]", ros_set_chassis_enable_srv.response.chassis_set_chassis_enable_result);
                if (ros_set_chassis_enable_srv.response.chassis_set_chassis_enable_result == 0)
                {
                    ROS_INFO("set chassis enable success, start run");
                }
                else
                {
                    ROS_INFO("set chassis enable fail, response_value[%d]", ros_set_chassis_enable_srv.response.chassis_set_chassis_enable_result);
                    select_key = 0;
                }
            }
            else
            {
                ROS_INFO("ROS call ros_set_chassis_enable_srv failed!");
                select_key = 0;
            }          
        } 
        cout << endl;
    }

    void responseTest(iapActionClient& ac) {
        switch (select_key) {
            case TestCase::circleleft :
                if (cur_time < 5) {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = current_angular;
                } else {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = 0;
                    select_key = 'p';
                }
                break;

            case TestCase::circleright :
                if (cur_time < 1) {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = -current_angular;
                } else {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = 0;
                    select_key = 'p';
                }
                break;                

            case TestCase::stop :
                if (cur_time < 1) {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = 0;
                } else {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = 0;
                    select_key = 'p';
                }
                break;

            case TestCase::forward:
                if (cur_time < 1) {
                    cmd_vel.linear.x = current_vel;
                    cmd_vel.angular.z = 0;
                } else {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = 0;
                    select_key = 'p';
                }      
                break;

            case TestCase::backward:
                if (cur_time < 1) {
                    cmd_vel.linear.x = -current_vel;
                    cmd_vel.angular.z = 0;
                } else {
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = 0;
                    select_key = 'p';
                }
                break; 
    
            case TestCase::Increase_max_speed:
                current_angular *= 1.1;
                current_vel *= 1.1;
                ROS_INFO("currently linear_vel %.4f angular_vel %.4f",
                         current_vel, current_angular);  
                select_key = 'p';
                break; 

            
            case TestCase::Decrease_max_speed:
                current_angular *= 0.9;
                current_vel *= 0.9;
                ROS_INFO("currently linear_vel %.4f angular_vel %.4f",
                         current_vel, current_angular);  
                select_key = 'p';
                break; 
            
            case TestCase::Increase_linear_speed:
                current_vel *= 1.1;
                ROS_INFO("currently linear_vel %.4f angular_vel %.4f",
                         current_vel, current_angular);  
                select_key = 'p';
                break; 
            
            case TestCase::Decrease_linear_speed:
                current_vel *= 0.9;
                ROS_INFO("currently linear_vel %.4f angular_vel %.4f",
                         current_vel, current_angular);  
                select_key = 'p';
                break;

            case TestCase::Increase_angular_speed:
                current_angular *= 1.1;
                ROS_INFO("currently linear_vel %.4f angular_vel %.4f",
                         current_vel, current_angular);  
                select_key = 'p';
                break; 
            
            case TestCase::Decrease_angular_speed:
                current_angular *= 0.9;
                ROS_INFO("currently linear_vel %.4f angular_vel %.4f",
                         current_vel, current_angular);
                select_key = 'p';
                break;

            default:
                cmd_vel.linear.x = 0;
                cmd_vel.angular.z = 0;
                setChassisEnable(false);
                ChassisControl(select_key); // update select_key
                cur_time = 0;
                break;
        }
        cur_time += 1.0f / rate;
    }

    bool ros_get_chassis_send_event_callback(segway_msgs::chassis_send_event::Request &req, segway_msgs::chassis_send_event::Response &res)
    {
        ROS_INFO("The ROS test node receives the event ID:%d", req.chassis_send_event_id);
        res.ros_is_received = true;
        return true;
    }
}

int main(int argc, char **argv) {
    // Initiate ROS
    ros::init(argc, argv, "chassis_response_test");
    ros::NodeHandle n_;
    
    n_.setParam("segwaySmartCarSerial", "ttyUSB0");

    //chassis
    ros::Publisher cmd_pub = n_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    // ros::Publisher cmd_enable_pub = n_.advertise<segway_msgs::motor_enable>("/cmd_enable", 1);

    chassis_send_event_srv_server = n_.advertiseService("chassis_send_event_srv", &ros_get_chassis_send_event_callback);

    ros_get_charge_mos_ctrl_status_cmd_client = n_.serviceClient<segway_msgs::ros_get_charge_mos_ctrl_status_cmd>("ros_get_charge_mos_ctrl_status_cmd_srv");
    ros_set_charge_mos_ctrl_cmd_client = n_.serviceClient<segway_msgs::ros_set_charge_mos_ctrl_cmd>("ros_set_charge_mos_ctrl_cmd_srv");
    ros_set_chassis_enable_cmd_client = n_.serviceClient<segway_msgs::ros_set_chassis_enable_cmd>("ros_set_chassis_enable_cmd_srv");
    ros_set_vel_max_cmd_client = n_.serviceClient<segway_msgs::ros_set_vel_max_cmd>("ros_set_vel_max_cmd_srv");//It needs to be consistent with the server-side name

    iapActionClient ac("ros_set_iap_cmd_action", true);
    ROS_INFO("Waiting for action server to start.");
    ac.waitForServer();
    ROS_INFO("Action server started.");

    ros::Rate loop_rate(rate);
    //system("stty -echo"); // 隐藏输入
	//system("stty raw"); // 设置终端非阻塞模式

    try
    {
        showHelp();
        system(STTY_US TTY_PATH);
        while(ros::ok()) {
	    cout<<"select key:"<<select_key;
            responseTest(ac);
            cmd_pub.publish(cmd_vel);
            loop_rate.sleep();
            ros::spinOnce();
                     
        }
        // cmd_enable.motor_enable = true;
        // cmd_enable_pub.publish(cmd_enable);
    }
    catch (...) {
        cout << "Error!"; }
    return 0;
}

