#include <iostream>
#include <string>

using namespace std;

class List{
    private:
        string* data;
        int capacity;
        int size;
        
        void grow(){
            capacity = capacity * 2;
            string* newData = new string[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        void shrinkToFit(){
            if(size == capacity){
                return;
            }
            if(size > 0){
                capacity = size;
            }else{
                capacity = 2;
            }
            string* newData = new string[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    public:
        List(){
            capacity = 2;
            size = 0;
            data = new string[capacity];
        }

        ~List(){
            delete[] data;
        }
        
        void add(string value){
            if(size == capacity){
                grow();
            }
            data[size] = value;
            size++;
        }

        string get(int index){
            if (index < 0 || index >= size) {
                std::cout << "ERROR: Invalid index" << endl;
                return "";
            }
            return data[index];
        }
        int getSize(){
            return size;
        }
        void remove(int index){
            if (index < 0 || index >= size) {
                std::cout << "ERROR: Invalid index" << endl;
                return;
            }
            for (int i = index; i < size - 1; i++){
                data[i] = data[i+1];
            }
            size--;
            shrinkToFit();
        }
        int find(string value){
            for(int i = 0;i < size;i++){
                if(data[i] == value){
                    return i;
                }
            }
            return -1;
        }
        void update(string value,int index){
            if (index < 0 || index >= size) {
                std::cout << "ERROR: Invalid index" << endl;
                return;
            }
            data[index] = value;
        }
        string first(){
            if(size > 0){
                return data[0];
            }
            std::cout << "ERROR: Invalid index" << endl;
            return "";
        }
        string last(){
            if(size > 0){
                return data[size-1];
            }
            std::cout << "ERROR: Invalid index" << endl;
            return "";
        }
        int count(string element){
            int countReturn = 0;
            for(int i = 0;i < size; i++){
                if(data[i] == element){
                    countReturn++;
                }
            }
            return countReturn;
        }
        void clear(){
            size = 0;
            shrinkToFit();
        }
};

int main() { 
    List list;
    return 0;
}
