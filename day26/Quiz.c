#include <stdio.h>

int main() {
    int score = 0;
    int answer;

    printf("Welcome to the Quiz Application!\n");
    printf("Answer the following questions by entering the correct option number.\n\n");

    // Question 1
    printf("Q1. What is the capital of India?\n");
    printf("1. Mumbai\n2. New Delhi\n3. Kolkata\n4. Chennai\n");
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! Correct answer is New Delhi.\n\n");
    }

    // Question 2
    printf("Q2. What is 5 + 3?\n");
    printf("1. 5\n2. 8\n3. 10\n4. 15\n");
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! Correct answer is 8.\n\n");
    }

    // Question 3
    printf("Q3. Which language is used for system programming?\n");
    printf("1. Python\n2. C\n3. HTML\n4. SQL\n");
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! Correct answer is C.\n\n");
    }

    // Final score
    printf("Quiz Over!\n");
    printf("Your final score is: %d out of 3\n", score);

    return 0;
}