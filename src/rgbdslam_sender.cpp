// rosservice call /rgbdslam/ros_ui frame # Capture single frames via
// rosservice call /rgbdslam/ros_ui_b pause false # Capture a stream of data
// rosservice call /rgbdslam/ros_ui send_all # Send point clouds with computed transformations (e.g., to rviz or octomap_server)
// rosservice call /rgbdslam/ros_ui_s save_cloud /tmp/mycloud.pcd # Save the registered pointclouds in the given file
// rosservice call /rgbdslam/ros_ui_s save_individual /tmp/filenameprefix # As above, but save every pointcloud in its own file 

#include <ros/ros.h>
#include <rgbdslam/rgbdslam_ros_ui.h>

class RequestSender {
	public:
	RequestSender(ros::ServiceClient client) : client(client) {
	}

	void sendRequest(const ros::TimerEvent& event) {
		ROS_INFO("Calling /rgbdslam/ros_ui send_all");

		rgbdslam::rgbdslam_ros_ui srv;
		srv.request.command = "send_all";

		client.call(srv);
	}

	private:
	ros::ServiceClient client;
};

void sendRequest(ros::ServiceClient client) {
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "rgbdslam_sender");
	ros::NodeHandle n;

	ros::ServiceClient client = n.serviceClient<rgbdslam::rgbdslam_ros_ui>("rgbdslam/ros_ui");
	RequestSender sender(client);

	ros::Timer timer = n.createTimer(ros::Duration(5.0), &RequestSender::sendRequest, &sender);

	ros::spin();
}
