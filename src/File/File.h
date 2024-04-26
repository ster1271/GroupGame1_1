#pragma once

class File
{
public:
	FILE* fp;
	errno_t err;

	File();
	~File();

	bool OpenFile(const char* file_name, const char* open_type);
	void CloseFile();
};