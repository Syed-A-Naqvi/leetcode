#include<cstdio>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_map>


struct PersonNode
{
    std::string name;
    std::string parent;
    int numDescendants;

    PersonNode* next;
    PersonNode* prev;
    
    PersonNode() : name(""), parent(""), numDescendants(0), next(nullptr), prev(nullptr) {};
    PersonNode(std::string name) : name(name), parent(""), numDescendants(0), next(nullptr), prev(nullptr) {};
    PersonNode(std::string name, std::string parent) : name(name), parent(parent), numDescendants(0), next(nullptr), prev(nullptr) {};
};

class ThroneInheritance {

private:
    std::unordered_map<std::string, PersonNode> familyTree;
    PersonNode* first;

public:
    ThroneInheritance(std::string kingName) {
        this->familyTree[kingName] = PersonNode(kingName);
        this->first = &this->familyTree[kingName];
    }
    
    void birth(std::string parentName, std::string childName) {

        // creating a new child        
        this->familyTree[childName] = PersonNode(childName, parentName);
        PersonNode* newChild = &this->familyTree[childName];

        // finding prev successor for new child
        PersonNode* person = &this->familyTree[parentName];
        for(int i = 0; i < this->familyTree[parentName].numDescendants; i++)
        {
            person = person->next;
        }

        // assigning new child
        newChild->next = person->next;
        newChild->prev = person;
        person->next = newChild;
        if(newChild->next != nullptr)
        {
            newChild->next->prev = newChild;
        }

        // incrementing number of descendants for all ancestors
        auto familyIT = this->familyTree.find(parentName);
        while (familyIT != this->familyTree.end())
        {
            familyIT -> second.numDescendants++;
            familyIT = this->familyTree.find(familyIT->second.parent);
        }

    }
    
    void death(std::string name) {
        
        // getting dead person
        PersonNode* dead = &this->familyTree[name];

        if(dead == this->first)
        {
            this->first = this->first->next;
            this->first->prev = nullptr;
        }
        else
        {
            // removing from line of succession
            if(dead->next != nullptr)
            {
                dead->next->prev = dead->prev;
            }
            dead->prev->next = dead->next;

            // decrementing number of descendants for all ancestors
            auto familyIT = this->familyTree.find(dead->parent);
            while (familyIT != this->familyTree.end())
            {
                familyIT -> second.numDescendants--;
                familyIT = this->familyTree.find(familyIT->second.parent);
            }        
        }

    }
    
    std::vector<std::string> getInheritanceOrder() {
        
        std::vector<std::string> succession;

        PersonNode* person = this->first;

        while (person != nullptr)
        {
            succession.push_back(person->name);
            person = person->next;
        }
        
        return succession;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<std::string> param_3 = obj->getInheritanceOrder();
 */

int main(int argc, char const *argv[])
{

    return 0;
}
