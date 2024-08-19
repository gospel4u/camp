#include <iostream>
#include <cctype>  // isdigit 함수가 포함된 헤더 파일
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

// 입력된 문자열이 유효한 정수인지 확인하는 함수
bool isValid(const std::string& str) {
    // 문자열이 3자리인지 확인
    if (str.length() != 3) {
        std::cout << "Please enter 3 digits." << std::endl;
        return false;
    }

    // 나머지 문자가 숫자인지 확인
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            std::cout << "Please enter only digits." << std::endl;
            return false;
        }
    }
    
    char digit1 = str[0];
    char digit2 = str[1];
    char digit3 = str[2];

    // 서로 다른 숫자인지 확인
    if (digit1 != digit2 && digit1 != digit3 && digit2 != digit3) {
        return true;
    } else {
        std::cout << "The digits must be unique." << std::endl;
        return false;
    }
}

// 랜덤으로 3자리 숫자 생성
std::string genRandom() {
    std::srand(std::time(0)); // random seed

    int digit1, digit2, digit3;

    // 첫 번째 자릿수는 1부터 9 중 하나
    digit1 = std::rand() % 9 + 1;

    // 두 번째 자릿수는 1부터 9 중 첫 번째와 다른 숫자
    do {
        digit2 = std::rand() % 9 + 1;
    } while (digit2 == digit1);

    // 세 번째 자릿수는 1부터 9 중 첫 번째와 두 번째와 다른 숫자
    do {
        digit3 = std::rand() % 9 + 1;
    } while (digit3 == digit1 || digit3 == digit2);

    int random_number = digit1 * 100 + digit2 * 10 + digit3;

    return std::to_string(random_number);
}

// 입력된 숫자와 랜덤으로 생성된 숫자를 비교하여 결과를 반환하는 함수
std::string getResult(const std::string& str, const std::string& answer) {
    int strike = 0;
    int ball = 0;

    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < answer.length(); j++) {
            if (str[i] == answer[j]) {
                if (i == j) {
                    strike++;
                } else {
                    ball++;
                }
            }
        }
    }

    return std::to_string(strike) + "S, " + std::to_string(ball) + "B";
}

int main() {
    int count = 0;
    std::string threedigits = genRandom(); // 랜덤 숫자 생성

    while (true) {
        if (count >= 3) {
            std::cout << "Invalid inputs exceeded 3 times." << std::endl;
            break;
        }  
        std::string input;
        std::cout << "Enter a 3-digit number: ";
        std::cin >> input;
        if (isValid(input)) {
            std::cout << "Random number: " << threedigits << std::endl;
            std::string result = getResult(input, threedigits);
            std::cout << result << std::endl;
            break;
        } else {
            std::cout << "Invalid input." << std::endl;
            count++;
        }
    }
    
    return 0;
}
