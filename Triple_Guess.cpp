#include<iostream>
#include<cstdlib>
#include<iomanip>

void StartGame();
void QuizGame();
int SumOfThreeNumbers(int ThreeDigitNumber);
int ProductOfThreeNumbers(int ThreeDigitNumber);
bool CheckAnswer(int GuessedAnswer, int CorrectAnswer);

int main() {
  std::cout<<"Hello and welcome to THE HOTEL \n" << "The Culling Game will begin shortly\n" << "Please take the quiz to start the game\n"<< std::endl;
  StartGame();

  return 0;
}

void StartGame() {
  std::cout<<"RULES: \n+You are given the sum and product of a three digit number\n+You need to guess the three digit number and muust type it in \n\n" <<std::endl;
  QuizGame();
}

void QuizGame() {
  
  int Level = 1;

  while(Level < 6){
    int Guess = 100 + (rand() % 899);
    // std::cout << Guess << std::endl;
    int Answer;

    int SumValueOfDigits = SumOfThreeNumbers(Guess);

    int ProductValueOfDigits = ProductOfThreeNumbers(Guess);

    std::cout << "\n-Sum of the digits: " << SumValueOfDigits << std::endl;
    std::cout << "-Product of the digits: " << ProductValueOfDigits << std::endl;
    std::cout << "Enter You Answer" << std::endl;

    std::cin >> Answer;

    bool AnswerStatus = CheckAnswer(Answer, Guess);

    if(AnswerStatus){
      ++Level;

      if(Level == 6){
        std::cout<<"You have qualified to play the culling game.\n ----SEE YOU SOON ;} ----\n"<<std::endl;
      }

    }

    else{
      std::cout<<"You are not fit for the culling game.\n ----PLAYER WILL BE TERMINATED----\n"<<std::endl;
      break;
    }

  }
}

int SumOfThreeNumbers(int ThreeDigitNumber){

  int Temp = 0;

  for(int i = 0; i < 3; i++){
    int Reminder = ThreeDigitNumber % 10;
    ThreeDigitNumber = ThreeDigitNumber / 10;
    Temp = Temp + Reminder;
  }

  return Temp;
}

int ProductOfThreeNumbers(int ThreeDigitNumber){

  int Temp = 0;

  for(int i = 0; i < 3; i++){
    int Reminder = ThreeDigitNumber % 10;
    ThreeDigitNumber = ThreeDigitNumber / 10;
    Temp = Temp * Reminder;
  }

  return Temp;
}

bool CheckAnswer(int GuessedAnswer, int CorrectAnswer){
  if(GuessedAnswer == CorrectAnswer){
    return true;
  }
  else{
    return false;
  }
}