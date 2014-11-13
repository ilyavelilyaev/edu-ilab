//
//  main.cpp
//  list
//
//  Created by Ilya Velilyaev on 29.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "list.h"
#include <dirent.h>
#include <errno.h>
#include <stack>

void readDirectory (List &list_of_files, const char * path) {
    DIR *dir = opendir(path);
    struct dirent *dirs;
    FilesNode *file = NULL;
    if (dir == NULL) {
        perror("ERROR!!!");
        return;
    }
    while ((dirs = readdir(dir)) != NULL) {
        file = new FilesNode;
        file->setName(dirs->d_name);
        file->setType(dirs->d_type);
        std::string new_path = path;
        new_path += "/";
        new_path += file->getName();
        file->setPath(new_path);
        
        if (file->getType() == "dir" && file->getName() != "." && file->getName() != "..") {
            readDirectory(list_of_files, file->getPath().c_str());
        }
        list_of_files.push_front(file);
    }
    closedir(dir);
    
}

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cout << "Bad arguments\n";
        return -1;
    }
    
    const char *my_start_dir = argv[1];
    const char *my_substr = argv[2];
    
    DIR *directory = opendir(my_start_dir);
    if (directory == NULL) {
        perror("ERROR!!!");
        return -1;
    }
    closedir(directory);
    std::cout << "You have entered directory: " << my_start_dir << std::endl << "Are you sure you want to continue? (y/n)\n";
    char temp = 0;
    std::cin >> temp;
    while (temp != 'y' && temp != 'n') {
        std::cout << "Enter 'y' or 'n'\n";
        std::cin >> temp;
    }
    if (temp == 'n') return 1; //did not want to continue
    
    std::cout << "Creating list of files in folder: " << my_start_dir << "\n";
    
    List list_of_files;
    
    readDirectory(list_of_files, my_start_dir);
    
  

    std::cout << "Now deleting all files without \"" << my_substr << "\" in its name\n";
    
  //  std::stack<long long> items_to_erase;
    FilesNode *temp_files_node = (FilesNode *)list_of_files.front(); 
    for (long long i = 0; i < list_of_files.size(); i++) {
        if (i % 100 == 0)  std::cout << "done " << i << " out of " << list_of_files.size() << "\n";
       // FilesNode *temp = ((FilesNode *)list_of_files[i]);
        std::size_t found = temp_files_node->getName().find(my_substr);
        if (found == std::string::npos || temp_files_node->getType() == "dir") {
         //   items_to_erase.push(i);
          if (i == 0) {
              list_of_files.pop_front();
              i--;
          } else if (i == list_of_files.size() - 1) {
              list_of_files.pop_back();
              i--;
          } else {
              Node *temp1 = temp_files_node->prev;
              Node *temp2 = temp_files_node->next;
              temp1->next = temp_files_node->next;
              temp2->prev = temp_files_node->prev;
              //delete temp_files_node;
              list_of_files.size()--; 
              i--;
             /* FilesNode *temp_files_node2 = temp_files_node;
              temp_files_node->prev->next = temp_files_node->next;
              temp_files_node = temp_files_node2;
              temp_files_node->next->prev = (FilesNode*)temp_files_node->prev;
              delete(temp_files_node2); */
         }
       }
        if (i != list_of_files.size() - 1) {
             Node *temp3 = temp_files_node;
             temp_files_node = (FilesNode *)(temp_files_node->next);
             delete temp3;
        }
    }
   /* 
    long long size = items_to_erase.size();
    
    for (long long i = 0; i < size; i++) {
        list_of_files.erase(items_to_erase.top());
        items_to_erase.pop();
    }
    */
    std::cout << "Now creating list of lists of files\n";
    
    List new_list;
    
    temp_files_node = (FilesNode *)list_of_files.front();

    for (long long i = 0; i < list_of_files.size(); i++) {
       // FilesNode *temp_files_node = new FilesNode;
       //*temp_files_node = *(FilesNode *)(list_of_files[i]);
        char letter = temp_files_node->getName()[0];
        bool exists_such_list = false;
        for (int j = 0; j < new_list.size(); j++) {
            if (((ListNode *)(new_list[j]))->firstLetter == letter) {
                exists_such_list = true;
                ((ListNode *)(new_list[j]))->list->push_front(temp_files_node);
            }
        }
        if (exists_such_list == false) {
            ListNode *tmp_node = new ListNode;
            tmp_node->firstLetter = letter;
            List *tmp_list = new List;
            tmp_list->push_front(temp_files_node);
            tmp_node->list = tmp_list;
            new_list.push_front(tmp_node);
        }
        if (i != list_of_files.size() - 1)
             temp_files_node = (FilesNode *)(temp_files_node->next);        
    }
    ListNode *temp_list_node = (ListNode *)new_list.front();   
    FilesNode *temp_list_files_node = NULL;
    for (long long i = 0; i < new_list.size(); i++) {
        std::cout << "letter: " << temp_list_node->firstLetter << "\nfiles:\n";
        List *temp_list = temp_list_node->list;
        temp_list_files_node = (FilesNode *)temp_list->front();
        for (int j = 0; j < temp_list->size(); j++) {
            std::cout << temp_list_files_node->getName() << "\n";
            if (j != temp_list->size() - 1)
                temp_list_files_node = (FilesNode *)temp_list_files_node->next;
        }
        std::cout << "\n";
        if (i != new_list.size() - 1)    
           temp_list_node = (ListNode *)(temp_list_node->next);
    }
    
    return 0;
}
