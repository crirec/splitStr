#pragma once
#include <vector>
#include <string>

void splitStr(std::vector<std::string>& vec, std::string srcStr, std::string msgStr)
{
	vec.clear();
	if (srcStr.find(msgStr) == std::string::npos) { vec.push_back("ERROR"); return; }
	size_t i[2] = {0,0};
	while (srcStr.find(msgStr) != std::string::npos)
	{
		if (srcStr.at(i[0]) == msgStr.at(i[1])) {
			bool found = 1;
			for(; i[1] < msgStr.length(); i[1]++)
				if (srcStr.at(i[0]+i[1]) != msgStr.at(i[1])) {
					found = 0;
				}
			i[1] = 0;
			if (found) {
				vec.push_back(srcStr.substr(0, i[0]));
				srcStr.erase(0, i[0] + msgStr.length());
				i[0] = 0;
			}
		}
		else i[0]++;
	}
	vec.push_back(srcStr);
}