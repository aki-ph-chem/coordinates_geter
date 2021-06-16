#include<iostream>

#include<vector>
#include<string>
#include<regex>

#include<fstream>
#include<sstream>



std::vector<double> split(std::string str){

    std::regex rep("[-0-9.]+");
    std::smatch m;
    std::vector<double> buff;

    while(std::regex_search(str,m,rep)){

        buff.push_back(stod(m.str()));

        str = m.suffix();
    }

    return buff;
}


int main(){

    std::string name_of_input_file;
    std::string name_of_output_file;
    int num_of_atoms;
    
    std::cout<<"Please enter the name of input file [.LOG]\n";
    std::cin>> name_of_input_file;

    std::cout<<"Please enter the name of output file\n";
    std::cin>>name_of_output_file;

    std::cout<<"Please enter the number of atoms.\n";
    std::cin>>num_of_atoms;


    std::ifstream ifs(name_of_input_file);
    std::string line;
    std::vector<std::string> buff;

    int num_of_loop = 0;
    while(getline(ifs,line)){

    buff.push_back(line);
    
    num_of_loop++;
    }

    bool loop_flag = true;

    while(loop_flag){

        int flag;

        flag = (int)buff[num_of_loop].find("Standard orientation:");

        loop_flag = flag <= 0;

        num_of_loop--;
    }

      num_of_loop++;
      num_of_loop += 5;

    //num_of_atoms = 21;
    std::vector<std::vector<double>> result;
    ;std::ofstream ofs(name_of_output_file);

    for(int i=0;i<num_of_atoms;i++){

        std::vector<double> output;

        output = split(buff[num_of_loop]);
        ofs<<output[0]<<" "<<output[1]<<" "<<output[2]<<" "<<output[3]<<" "<<output[4]<<" "<<output[5]<<std::endl;
        
        result.push_back(split(buff[num_of_loop]));

        num_of_loop++;
    }

    for(int i=0;i<num_of_atoms;i++){

        std::cout<<result[i][0]<<","<<result[i][1]<<","<<result[i][2]<<","<<result[i][3]<<","<<result[i][4]<<","<<result[i][5]<<std::endl;
    }

    return 0;
}

