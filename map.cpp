#include "map.hpp"

Map::Map(){};

void Map::writeMap(int n, int digit)
{
	m_mutex.lock();
	m_map.insert({n,digit});
	m_mutex.unlock();

}

int Map::readMap(int n)
{
	return m_map[n];
}
