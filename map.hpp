#pragma once
#include <unordered_map>
#include <mutex>

class Map
{
	public:
	Map();
	void writeMap(int n , int digit);
	int readMap(int n);
	private:
	std::mutex m_mutex;
	std::unordered_map<int/*n*/ , int/*digit*/ > m_map;


};
