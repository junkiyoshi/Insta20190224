#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int deg = 0; deg < 360; deg += 1) {

		auto noise_point = glm::vec2(cos(deg * DEG_TO_RAD), sin(deg * DEG_TO_RAD));
		int u = ofMap(ofNoise(noise_point.x * 0.5, noise_point.y * 0.5, ofGetFrameNum() * 0.01), 0, 1, 0, 720);

		auto start = this->make_point(250, 50, (u)* DEG_TO_RAD, deg * DEG_TO_RAD);
		auto end = this->make_point(250, 50, (u + 180) * DEG_TO_RAD, deg * DEG_TO_RAD);

		ofDrawSphere(start, 3);
		ofDrawSphere(end, 3);

		ofDrawLine(start, end);
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	float x = (R + r * cos(u)) * cos(v);
	float y = (R + r * cos(u)) * sin(v);
	float z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}