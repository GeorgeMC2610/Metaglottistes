#include <iostream>
#include <string> //for string functions
#include <regex> //for regular expressions
#include <iomanip> //for text allign
#include <fcntl.h> 
#include <io.h> //these are used in order to input/output greek letters

#include "Threenode-tree_class.h" //our threenode-tree class header file

using namespace std;

int main()
{        
    _setmode(_fileno(stdout), _O_WTEXT); //these are used in order to input/output greek letters 
    _setmode(_fileno(stdin), _O_WTEXT);  //(also wcout,wcin,wregex,wstring,wchar_t and L before some outputs, are beeing used for same reason)
     

                                                                  //SYNTAX TABLE


    wstring syntax_table[5][8] = {{L"",L"(",L")",L"α",L"β",L"*",L"-",L"+"}, //a 2d array that contains the rules we are going to use in top-down parser
                                  {L"S",L")X("},                            //We put characters in opposite order, to be easier to modifiy correct the stack string 
                                  {L"X",L"ZY",L"",L"ZY",L"ZY"},
                                  {L"Y",L"S",L"",L"α",L"β"},
                                  {L"Z",L"",L"ε",L"",L"",L"X*",L"X-",L"X+"}}; //the rest elements are ""

    
                        
                                                                    //USER INPUT
    
    
    wstring input; //a string variable to store user's input. We are going to edit this string along the procedure, in order to show the remaining input characters.

    while (true) //a loop that breaks only when the user gives correct input
    {
        wcout << "Give an expression that contains only the following terminal characters: ";
        wcout << L"(, ), α, β, *, -, +"<< endl;

        wcin >> input;

        bool match = regex_match(input, wregex(L"[()αβ*+-]+")); //If user's expression includes only (, ), α, β, *, -, + characters, match=true otherwise match=false 

        if (match) { //if expression matches
            input.append(L"$"); //add the $ character at the end of input, in order to begin the topdown parser procedure
            break; //break loop
        }
        else //else notify user for invalid input
        {
            wcout << "\nIncorrect expression format\n" << endl;
        }
    }

                                                                 //START OF PROCEDURE
    

    wstring stack = L"$S"; //At the begining, stack has only $ and S(starting character) characters
    wstring stack_top, input_start; //strings to store stack's top and input's first characters

    ThreenodeTree* tree = new ThreenodeTree ('S'); //make the first tree node, that has as key the starting character
    ThreenodeTree* root = tree; //root pointer is beeing used in order to point at the node we are going to expand

    ThreenodeTree* rightnd = 0;
    ThreenodeTree* middlend = 0;
    ThreenodeTree* leftnd = 0; //Children node we are going to add at each expansion of a root node

    wcout<<"\n"<<setw(25)<<left<<"Stack:"
    << setw(25)<< left << "Input:"
    << setw(25) << left << "Table element:"
    << "Production:" << endl; //Print the topdown parser's details (setw is beeing used for text allign)
    
    while (true) //a loop that breaks only when the expression has been recognized or not
    {
        stack_top = stack[stack.length()-1]; //Every time we repeat, we are storing the last string stack character (stack's top) in stack_top
        input_start = input[0]; //Every time we repeat, we are storing the first input character in input_start

        wcout << setw(25) << left << stack << setw(25) << left << input; //print stack and input strings at their current state


                                                             //FIRST STACK CASE


        if (regex_match(stack_top, wregex(L"[SXYZ]")) && input_start!=L"$") //if stack_top character is a non-terminal symbol and input has not yet finished
        {
            root = ThreenodeTree::searchNewrootInpreorder(tree, stack[stack.length() - 1]); //search for the node we are going to expand in syntax tree.
                                                                                            //We have to find the correct node that has the same key character
                                                                                            //as stack's top character(see header file for more info)


                                                            //RULE INDEX IN SYNTAX TABLE

                            
            wcout << "M(" << stack_top << ","<< input_start << setw(20) << left << ")"; //print the table's index we are going to check for a replacement rule

            int i, j;
            for (i = 1; i < 5; i++) 
            {
                if (syntax_table[i][0] == stack_top) //check all the values of first syntax table's column, in order to find the non terminal symbol of stack's top
                    break;                
            }

            for (j = 1; j < 8; j++) 
            {
                if (syntax_table[0][j] == input_start) //check all the values of first line, in order to find the terminal symbol of input's begining
                    break;
            }

            //i has the line index and j has the column index
                                            


                                                              //CONDITIONS FOR RULES

                
            if (syntax_table[i][j] != L"") //if that index of table has a rule
            {

                                                                //tree expansion  


                switch (syntax_table[i][j].length()) //check the replacement rule length, in order to expand the tree node correctly
                {
                    case 1: //if len = 1
                        middlend = new ThreenodeTree(syntax_table[i][j][0]);
                        root->middlenode = middlend; //Add a middle child node in current root node, with the rule's character as key
                        break;

                    case 2: //if len = 2 (rule characters are at opposite direction, so 1st char --> right child , 2nd char --> left child)
                        leftnd = new ThreenodeTree(syntax_table[i][j][1]);
                        root->leftnode = leftnd; //Add a left child node in current root node, with the rule's second character as key

                        rightnd = new ThreenodeTree(syntax_table[i][j][0]);
                        root->rightnode = rightnd; //Add a right child node in current root node, with the rule's first character as key
                        break;

                    case 3: //if len = 3 (1st char --> right child , 2nd char --> middle child, 3rd char --> left child)
                        leftnd = new ThreenodeTree(syntax_table[i][j][2]);
                        root->leftnode = leftnd;

                        middlend = new ThreenodeTree(syntax_table[i][j][1]);
                        root->middlenode = middlend;

                        rightnd = new ThreenodeTree(syntax_table[i][j][0]);
                        root->rightnode = rightnd;

                        break;
                }
                                                               //string stack modification                                        


                stack.erase(stack.end() - 1); //erase string stack last not terminal symbol

                if (syntax_table[i][j] != L"ε") //if the rule we got is not ε (if it is, we are not adding anything in string stack)
                    stack.append(syntax_table[i][j]); //append the new characters of the corresponding rule in string stack
                                                        

                                                                //printing results

                wcout << stack_top << "-->";

                for (int k = syntax_table[i][j].length() - 1; k >= 0; k--)
                    wcout << syntax_table[i][j][k]; //print in opposite order the characters of replacement rule 

                wcout << endl;
            }
            else //if there is not a rule in that index of syntax table 
            {
                wcout << "\n\nThere is not any replacement rule on table index: "
                << "[" << i << "]" << "[" << j << "]" << " so the expression is not beeing recognized;";
                break; //stop procedure and exit
            }           
        }

                                                               //REST STACK CASES

                        
        else if(stack_top != L"$" && input_start != L"$") //else, if there is a terminal character at stack top and input has not yet finished
        {                                                 //(that means stack top and input begining have the same terminal characters)

            stack.erase(stack.end() - 1); //remove stack string last character
            input.erase(input.begin()); //remove input first character
            wcout << endl;
            //continue procedure...
        }
        else if (stack_top != L"$" && input_start == L"$") //else, if stack is not empty but input has finished(the expression is not beeing recognized)
        {

            wcout << "\n\nStack is not empty, so the expression is not beeing recognized";
            break; //stop procedure and exit

        }else if(stack_top == L"$" && input_start != L"$") //else, if stack is empty but input has not finished(the expression is not beeing recognized)
        {
            wcout << "\n\nUnable to recognize all input characters, so the expression is not beeing recognized";
            break; //stop procedure and exit
        }
        else //else, stack should be empty and input should be finished(the expression has been recognized)
        {
            wcout << "\n\nStack is empty, so the expression has been recognized\n" << endl;

            wcout << "Syntax tree output in preorder: ";
            tree->Preorder_Output(); 
            wcout << "\nSyntax tree output in inorder: ";
            tree->Inorder_Output();
            wcout << "\nSyntax tree output in postorder: ";
            tree->Postorder_Output();
            break; //end of procedure
        }
    } 

    return 0;
}

