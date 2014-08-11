// rosservice call /rgbdslam/ros_ui frame # Capture single frames via
// rosservice call /rgbdslam/ros_ui_b pause false # Capture a stream of data
// rosservice call /rgbdslam/ros_ui send_all # Send point clouds with computed transformations (e.g., to rviz or octomap_server)
// rosservice call /rgbdslam/ros_ui_s save_cloud /tmp/mycloud.pcd # Save the registered pointclouds in the given file
// rosservice call /rgbdslam/ros_ui_s save_individual /tmp/filenameprefix # As above, but save every pointcloud in its own file 

#include <ros/ros.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "rgbdslam_sender");
	ros::NodeHandle n;
}
