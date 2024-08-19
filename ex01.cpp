#include <iostream>
#include <cctype>  // isdigit 함수가 포함된 헤더 파일
#include <string>

// 입력된 문자열이 유효한 정수인지 확인하는 함수
bool isValid(const std::string& str) {
    // 문자열이 20자리 이상이면 정수가 아님
    if (str.length() > 20 || (str.length() > 20 && str[0] != '-')) {
        std::cout << "Please enter an integer with less than 20 digits." << std::endl;
        return false;
    }

    // 빈 문자열인 경우 정수가 아님
    if (str.empty()) {
        std::cout << "Please enter a non-empty input." << std::endl;
        return false;
    }

    // 음수의 경우 첫 번째 문자는 '-'이어야 함
    size_t startIndex = 0;
    if (str[0] == '-') {
        startIndex = 1;
        if (str.length() == 1) {  // '-'만 입력된 경우
            std::cout << "Invalid input. Please enter a number." << std::endl;
            return false;
        }
    }

    // 나머지 문자가 숫자인지 확인
    for (size_t i = startIndex; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            std::cout << "Please enter a number." << std::endl;
            return false;
        }
    }
    return true;
}

// 입력된 문자열에 천 단위로 콤마를 삽입하는 함수
std::string addCommas(const std::string& str) {
    std::string result;
    int count = 0;

    // 음수 처리
    int startIndex = 0;
    if (str[0] == '-') {
        result += '-';
        startIndex = 1;
    }

    // 문자열을 뒤에서부터 처리
    for (int i = str.length() - 1; i >= (startIndex); --i) {
        result.insert(result.begin() + (result[0] == '-' ? 1 : 0), str[i]);
        count++;
        // 3번째마다 콤마를 추가 (가장 앞쪽에는 추가하지 않음)
        if (count % 3 == 0 && i != (startIndex)) {
            result.insert(result.begin() + (result[0] == '-' ? 1 : 0), ',');
        }
    }
    return result;
}

int main() {
    
    int count = 0;

    while (true) {
        if (count >= 3) {
            std::cout << "Invalid inputs exceeded 3 times." << std::endl;
            break;
        }  
        std::string input;
        std::cout << "Enter an integer (less than 20 digits): ";
        std::cin >> input;
        if (isValid(input)) {
            std::string formattedInput = addCommas(input);
            std::cout << "You entered the integer: " << formattedInput << std::endl;
            break;
        } else {
            std::cout << "Invalid input." << std::endl;
            count++;
        }
    }
    
    return 0;
}
