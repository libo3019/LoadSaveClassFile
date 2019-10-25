#include <basic_type_serialization.h>
#include"class_file_struct.hh"
#include <windows.h>
using namespace compilers::mylanguage;
int main()
{
	class_declartion klass;
	std::vector<std::string> templates;
	templates.push_back("T1");
	templates.push_back("T2");
	templates.push_back("T3");
	std::vector<std::string> ifs;
	ifs.push_back("if1");
	ifs.push_back("if2");
	ifs.push_back("if3");
	std::list<std::vector<std::string>> ifs_list;
	ifs_list.push_back(ifs);
	ifs.clear();
	ifs.push_back("if31");
	ifs.push_back("if32");
	ifs.push_back("if33");
	ifs_list.push_back(ifs);
	std::map<std::string, std::list<std::vector<std::string>>> data;
	data.insert(std::make_pair("data1", ifs_list));

	ifs.clear();;
	ifs.push_back("if111");
	ifs.push_back("if112");
	ifs.push_back("if113");
	ifs_list.clear();;
	ifs_list.push_back(ifs);
	ifs.clear();
	ifs.push_back("if321");
	ifs.push_back("if322");
	ifs.push_back("if323");
	ifs_list.push_back(ifs);
	data.insert(std::make_pair("data2", ifs_list));

	std::vector<float> ifs1;
	ifs1.push_back(1.1f);
	ifs1.push_back(1.2f);
	ifs1.push_back(1.3f);
	std::list<std::vector<float>> ifs1_list;
	ifs1_list.push_back(ifs1);
	ifs1.clear();
	ifs1.push_back(2.1f);
	ifs1.push_back(2.2f);
	ifs1.push_back(2.3f);
	ifs1_list.push_back(ifs1);
	std::map<std::string, std::list<std::vector<float>>> data1;
	data1.insert(std::make_pair("data1", ifs1_list));

	ifs1.clear();;
	ifs1.push_back(3.1f);
	ifs1.push_back(3.2f);
	ifs1.push_back(3.3f);
	ifs1_list.clear();;
	ifs1_list.push_back(ifs1);
	ifs.clear();
	ifs1.push_back(5.91f);
	ifs1.push_back(5.92f);
	ifs1.push_back(5.93f);
	ifs1_list.push_back(ifs1);
	data1.insert(std::make_pair("data2", ifs1_list));

	klass.set_klass_name("class1")
		.set_super_klass_name("super1")
		.set_template_parameters(templates)
		.set_interfaces(data)
		.set_interfaces1(data1);
	std::basic_string<unsigned char> buf;
	klass.serialize(buf);
	FILE *fp;
	fp = fopen("1.dat", "wb");
	fwrite(&buf[0], 1, buf.size(), fp);
	fclose(fp);
	fp = fopen("1.dat", "rb");
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	unsigned char *buf1 = new unsigned char[size];
	fread(buf1, 1, size, fp);
	class_declartion klass1;
	size_t pos = 0;
	int result = klass1.deserialize(buf1, pos, size);
	if (result != 0)
	{ 
		printf("Have some bugs\n");
	}
	else
	{
		printf("Perhaps no bugs.\n");
	}
	class_declartion klass3;
	HMODULE hExe = ::LoadLibraryA("D:\\MyTasks\\Compilers\\nasmwin64win\\module1.exe");
	assert(hExe != NULL);
	unsigned char * data_start = (unsigned char *)(GetProcAddress(hExe, "klass_name_type_tab"));
	unsigned char * data_end = (unsigned char *)(GetProcAddress(hExe, "klass_name_type_end"));
	int data_size = (int)(data_end - data_start);
	pos = 0;
	result = klass3.deserialize(data_start, pos, data_size);
	if (result != 0)
	{
		printf("Have some bugs\n");
	}
	else
	{
		printf("Perhaps no bugs.\n");
	}
	return 0;
}