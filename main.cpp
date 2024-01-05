#include <iostream>

void drawTable(std::string table[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout<<table[i][j];
        }
        std::cout<<""<<std::endl;
    }
}
bool checkHoz(std::string table[3][3] ,std::string symbol){
    int cCount = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (table[i][j] == symbol) {
                cCount++;
            }
        }
        if (cCount == 3) {
            return true;
        }
        cCount = 0;
    }

    return false;
}
bool checkVer(std::string table[3][3] ,std::string symbol){
    int cCount = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (table[j][i] == symbol) {
                cCount++;
            }
        }
        if (cCount == 3) {
            return true;
        }
        cCount = 0;
    }
    return false;
}
bool checkDiag(std::string table[3][3] ,std::string symbol){
    int cCount = 0;
    int index[] = {0,4,8,2,4,6};
    for (int i = 0; i < 6; ++i) {
        if(table[index[i]/3][index[i]%3] == symbol){
            cCount ++;
        }
        if(cCount == 3){
            return true;
        }
        if(i == 2){
            cCount = 0;
        }
    }
    return false;
}
bool checkWin(std::string table[3][3] ,std::string symbol){
    return checkVer(table,symbol) || checkHoz(table,symbol) || checkDiag(table,symbol);
}

bool placePoint(std::string table[3][3],std::string symbol){
    std::cout<<"Enter a pos: ";
    int num;std::cin>>num;num --;
    if(num <= 8 && num >= 0 && table[num/3][num%3] != " X " && table[num/3][num%3] != " O "){
        table[num/3][num%3] = symbol;
        return true;
    }
    return false;
}

class Job{
public:
    std::string company;
    int pay;
    std::string role;
    Job(std::string company_, int pay_, std::string role_){
        company = company_;
        pay = pay_;
        role = role_;
    }
};

int main() {
    bool isDraw = true;
    std::string table[3][3] = {{" 1 "," 2 "," 3 "},{" 4 "," 5 "," 6 "},{" 7 "," 8 "," 9 "}};
    for (int i = 0; i < 9; ++i) {
        drawTable(table);

        std::string sym = " O ";
        if(i % 2 == 0){
            sym = " X ";
        }

        while (!placePoint(table,sym)){}
        if(checkWin(table,sym)){
            std::cout<<sym<<" Wins"<<std::endl;
            isDraw = false;
            break;
        }
    }
    if(isDraw){
        std::cout<<"You Lose Draw"<<std::endl;
    }


    return 0;
}
