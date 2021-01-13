#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 10000
#define MAX_CHAR_LINE 200

typedef struct{
	int step;
	int index;
}instructs;

char* get_word(char* line, int index){
	char** words = (char**)malloc(100 * sizeof(char*));
	char* word = " ";
	int count = 0;

	word = strtok(line, " ");

	while(word != NULL){
      words[count] = word;
      word = strtok(NULL, " ");
			count++;
   }

	 char* buffer = words[index-1];
	 return buffer;
}

void get_sentence(char** lines, instructs* instruction, int rows, char* sentence){
	int steps[rows];
	int indexs[rows];

	steps[0] = instruction[0].step;
	indexs[0] = instruction[0].index;

	for(int i = 1; i < rows; i++){
		steps[i] = steps[i-1] + instruction[i].step;
		indexs[i] = instruction[i].index;
	}

	for(int i = 0; i < rows; i++){
		char* word = get_word(lines[steps[i] - 1], indexs[i]);
		strcat(sentence, " ");
		strcat(sentence, word);
	}
	printf("%s\n",sentence);

}

int main(){
	FILE* f_book = fopen("alice.txt", "r");
	FILE* f_instructions = fopen("instructions.txt", "r");

	int step = 0;
	int index = 0;
	int rows = 0;

	while(!feof(f_instructions)){
		fscanf(f_instructions,"%d %d",&step,&index); //just for one line
		if(!feof(f_instructions)){
			rows++;
		}
	}

	instructs* instruction = (instructs*)malloc(rows * sizeof(instructs));

	fseek(f_instructions, 0, SEEK_SET); //SEEK_SET SEEK_CUR SEEK_END

	for(int i = 0; i < rows; i++){
		fscanf(f_instructions, "%d %d", &instruction[i].step, &instruction[i].index);
	}

	fclose(f_instructions);

	char** all_of_book = (char**)malloc(sizeof(char*) * MAX_LINE);

	for(int i = 0; i < MAX_LINE; i++){
		all_of_book[i] = (char*)malloc(sizeof(char) * MAX_CHAR_LINE);
	}
	for(int i = 0; i < MAX_LINE; i++){
		fgets(all_of_book[i],MAX_CHAR_LINE,f_book);
	}

	char* sentence = (char*)malloc(sizeof(char) * MAX_CHAR_LINE);
	get_sentence(all_of_book, instruction, rows, sentence);

	free(instruction);

	return 0;
}
