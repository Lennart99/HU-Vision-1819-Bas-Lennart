#include <chrono>
#include <iostream>

void test1() {
	auto start = std::chrono::high_resolution_clock::now();

	volatile unsigned int res;
	for(volatile unsigned int i = 0; i<1'000'000'000; i++) {
		auto r = i*4;
		auto g = 3*i;
		auto b = i;
		res = (r+g+b)/3;
		//res = (r/3)+(g/3)+(b/3);
		//res = (r*0.21)+(g*0.72)+(b*0.07);
	}

	auto finish = std::chrono::high_resolution_clock::now();
	std::cout<<"test1: "<<std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count()<<" ms\n";
}

void test2() {
	auto start = std::chrono::high_resolution_clock::now();

	volatile unsigned char res;
	for(volatile unsigned int i = 0; i<1'000'000'000; i++) {
		auto r = i*4;
		auto g = 3*i;
		auto b = i;
		//res = (r+g+b)/3;
		res = (r/3)+(g/3)+(b/3);
		//res = (r*0.21)+(g*0.72)+(b*0.07);
	}

	auto finish = std::chrono::high_resolution_clock::now();
	std::cout<<"test2: "<<std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count()<<" ms\n";
}

void test3() {
	auto start = std::chrono::high_resolution_clock::now();

	volatile unsigned int res;
	for(volatile unsigned int i = 0; i<1'000'000'000; i++) {
		auto r = i*4;
		auto g = 3*i;
		auto b = i;
		//res = (r+g+b)/3;
		//res = (r/3)+(g/3)+(b/3);
		res = (r*0.21)+(g*0.72)+(b*0.07);
	}

	auto finish = std::chrono::high_resolution_clock::now();
	std::cout<<"test3: "<<std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count()<<" ms\n";
}

int main() {
	test1();
	test2();
	test3();

	return 0;
}