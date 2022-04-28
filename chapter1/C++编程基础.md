#### 01 命名空间
#### 02 vector
push_back方法
size方法
#### 03 文件读写
1. 头文件fstream
2. 写文件————创建ofstream
        ofstream outfile("filename");//以覆盖的方式写
        ofstream outfile("filename", ios_base::app);//以追加的方式写
3. 读文件————创建ifstream
        ifstream infile("filename");
4. 读写文件——创建fstream
- fstream iofile("data.txt",ios_base::in | ios_base::app);
- 以追加模式写的，无论在何处都会写在文件尾部
- ios_base::in    //打开进行读取
            out     //打开进行写入
            app     //每次写入前查找到流的末尾（即追加）
            ate     //打开后立即查找到流的末尾
            binary  //二进制模式打开
            trunc   //打开后删除文件内容
- iofile.seekg(0);    //定位到文件开头       
- 读后写要先清除
        iofile.clear(); 
    因为在前面对绑定的文件流做读操作时file流对象已经读到EOF结束状态，就没法在对文件做其它操作必须要重置流的条件状态后才能继续对流做其它操作
#### 04 sort()
字典序中大写都小于小写，如[练习1.7](./exe1.7.cpp)中的txt与out.txt