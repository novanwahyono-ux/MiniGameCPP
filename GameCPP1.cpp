#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>

//End Of File Function
[[nodiscard]] bool saver() {
    if (std::cin.eof()) {
        std::cerr << "[!]DANGER. CLOSING PROGRAM FOR SAFETY.\n";
        return false;
    }

    if (std::cin.fail()) {
        std::cin.clear();
    }

    return true;
}

//Buffer Clear Function
void bufferClear() {
    if (std::cin.fail()) {
        std::cin.clear();
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//Main Program
int main() {
    //Competitive Programing
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //Question Variabel Using Array
    std::string question[] {
        "1. Which U.S. state is home to Silicon Valley, the global hub for technology and innovation?",
        "2. Who was the first President of the United States, leading the nation after winning the Revolutionary War?",
        "3. What is the total number of voting Senators in the U.S. Congress, given that each state sends 2 representatives?",
        "4. Which city is known as a major tech hub in the Pacific Northwest and serves as the primary headquarters for Microsoft and Amazon?",
        "5. What do the 13 horizontal red and white stripes on the national flag of the United States represent?",
        "6. What is the name of the major mountain range that stretches across the western United States, from New Mexico up into Canada?",
        "7. The First Amendment of the U.S. Constitution is widely famous for guaranteeing which fundamental right?",
        "8. On December 7, 1941, the U.S. naval base at Pearl Harbor was attacked, drawing the U.S. into WWII. In which state is Pearl Harbor located?",
        "9. What is the name of the street in Manhattan that serves as the symbol of the U.S. financial industry and houses the New York Stock Exchange?",
        "10. In the U.S. presidential election system, citizens do not vote for the president directly, but through an institution known as what?"
    };

    //Option Variabel Using 2D Array
    std::string optionAnswer[][4] = {
        {"A. New York", "B. Washington", "C. California", "D. Texas"},
        {"A. Thomas Jefferson", "B. George Washington", "C. Abraham Lincoln", "D. Benjamin Franklin"},
        {"A. 50", "B. 100", "C. 435", "D. 538"},
        {"A. San Francisco", "B. Seattle", "C. Boston", "D. Austin"},
        {"A. The number of the first presidents", "B. The number of the original constitutional amendments", "C. The 13 original colonies that declared independence", "D. The number of warships during the American Revolution"},
        {"A. Appalachian Mountains", "B. Rocky Mountains", "C. Sierra Nevada", "D. Cascade Range"},
        {"A. The right to bear arms", "B. Freedom of speech, religion, and the press", "C. The abolition of slavery", "D. Women's suffrage (the right to vote)"},
        {"A. California", "B. Florida", "C. Alaska", "D. Hawaii"},
        {"A. Broadway", "B. Fifth Avenue", "C. Wall Street", "D. Madison Avenue"},
        {"A. Popular Vote", "B. Electoral College", "C. Parliamentary System", "D. District Allocation"}
    };

    // Answer Key Variabel Using Array
    char answerKey[] = {'C', 'B', 'B', 'B', 'C', 'B', 'B', 'D', 'C', 'B'};

    // Variabel Size For Index
    size_t size = sizeof(question) / sizeof(question[0]);

    // Variabel Score
    size_t score = 0;

    //User Input Variabel
    char userInput;

    for (size_t i = 0; i < size; i++) {
        std::cout << question[i] << "\n";

        for (size_t j = 0; j < 4; j++) {
            std::cout << "     " << optionAnswer[i][j] << "\n";
        }

        std::cout << "CHOOSE OPTION: " << std::flush;
        if (!(std::cin >> userInput)) {
            if (!(saver())) return 1;
            bufferClear();
            std::cerr << "FATAL ERROR! PLEASE INPUT BETWEEN A, B, C, OR D\n";
            return EXIT_FAILURE;
        }
        bufferClear();
        userInput = std::toupper(static_cast<unsigned char>(userInput));

        if (userInput == answerKey[i]) {
            std::cout << "CORRECT ANSWER\n";
            score++;
        } else {
            std::cout << "YOUR INPUT INCORRECT!\n" << answerKey[i] << " IS THE CORRECT ANSWER\n";
        }
    }
    std::cout << "\n";

    std::cout << "=============== YOUR GRADE ===============\n";
    size_t totalScore = (score * 100) / size;
    std::cout << "YOUR TOTAL SCORE IS: " << totalScore << "\n";
    std::cout << "CONGRATULATION BOY!!!\n";
}
