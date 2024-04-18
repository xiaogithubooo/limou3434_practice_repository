#include <iostream>
#include <string>
#include <fstream>
#include "bundle.h"

int main(int argc, char const *argv[])
{
    //1.获取文件名字
    if (argc < 3) return -1;
    std::cout << "原始文件路径" << argv[1];
    std::cout << "压缩文件路径" << argv[2];
    std::string iFileName = argv[1];
    std::string oFileName = argv[2];

    //2.获取原始文件的大小
    std::ifstream ifs;
    ifs.open(iFileName, std::ios::binary);
    ifs.seekg(0, std::ios::end); //偏移量 off, 基准 way, 这里就将文件读取位置移动到文件的末尾
    size_t fsize = ifs.tellg(); //获取到文件大小
    ifs.seekg(0, std::ios::beg);

    //3.读取文件内容到文件流中
    std::string body;
    body.resize(fsize); //调整为打开文件的大小
    ifs.read(&body[0], fsize); //读取文件的内容

    //4.将原始文件转化为压缩文件
    std::string packed = bundle::pack(bundle::LZIP, body); //选择 LZIP 格式对文件内容进行压缩
    std::ofstream ofs;
    ofs.open(oFileName, std::ios::binary);
    ofs.write(&packed[0], packed.size()); //保存压缩后的内容

    //5.回显压缩信息
    std::cout
        << "压缩成功" << std::endl
        << "压缩前:" << fsize << " "
        << "压缩后:" << packed.size()
        << std::endl;

    //6.释放文件资源
    ifs.close();
    ofs.close();

    return 0;
}