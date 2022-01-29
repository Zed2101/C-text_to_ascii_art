#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

void convert_string_to_ascii(string ,int);

int main() {
  // change the string to convert to ascii
  // change the numbre in the function to change the font
  convert_string_to_ascii("wasd", 7);

  return 0;
}

void convert_string_to_ascii(string mystring, int font) {
  int LETTER_OFFSET;
  string FILE_NAME = "";

  switch (font) {
    case 1:
      LETTER_OFFSET = 16;
      FILE_NAME = "text1.txt";
      break;
    case 2:
      LETTER_OFFSET = 4;
      FILE_NAME = "text2.txt";
      break;
    case 3:
      LETTER_OFFSET = 3;
      FILE_NAME = "text3.txt";
      break;
    case 4:
      LETTER_OFFSET = 5;
      FILE_NAME = "text4.txt";
      break;
    case 5:
      LETTER_OFFSET = 3;
      FILE_NAME = "text5.txt";
      break;
    case 6:
      LETTER_OFFSET = 6;
      FILE_NAME = "text6.txt";
      break;
    case 7:
      LETTER_OFFSET = 11;
      FILE_NAME = "text7.txt";
      break;
    default:
      cout << "Invalid font!" << endl;
      return;
  }
  
  vector <int> offsets_to_apply;

  int string_length = mystring.length();

  for (int i = 0; i < string_length; i++) {
    int offset = (toupper(mystring[i]) - 65) * LETTER_OFFSET + 2;
    offsets_to_apply.push_back(offset);
  }

  ifstream myfile (FILE_NAME);

  bool line_read = false;
  string _string;

  while( myfile && !line_read ) {
    for (size_t i = 0; i < LETTER_OFFSET; i++) {
      for (size_t j = 0; j < string_length; j++) {
        for (size_t k = 0; k < offsets_to_apply[j] + i; k++)
          getline(myfile, _string);
        cout << _string;
        myfile.clear();
		myfile.seekg(0);
      }
      cout << endl;
    }
    line_read = true;
  }

  myfile.close();
}
