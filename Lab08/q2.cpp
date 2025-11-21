/*Question#2: Reuse the methods from above question 1 and complete below question:
You are required to implement a game titled “BattleQuest: BST Arena” using a Binary Search Tree (BST) where each node in the tree stores a Combatant object. This game simulates a classic RPG-style battle between a player’s team of heroes and a team of enemies. The core challenge involves managing two separate BSTs — one for the player’s team and another for the enemy team — where each node contains a Combatant object with attributes such as name, health points (HP), and attack power. The game follows a strict turn-based combat system, where the player’s team and the enemy team alternate turns. Only the frontline combatant — defined as the node with the smallest key value (i.e., the leftmost node in the BST) participates in combat during each turn.
When a combatant’s health drops to zero or below, that combatant is removed from their respective BST. The next available combatant in the tree (the new leftmost node) becomes the frontline fighter for the following turn.The b attle continues until one team’s BST becomes empty, determining the winner. The player’s team should be initialized with five heroes. The enemy team should be initialized with five enemies. Both trees should be constructed using insertions according to the BST property based on the combatant’s name or unique ID. The player always attacks first in each round, followed by the enemy counterattack. During an attack: The attacker’s damage = base attack power + random value (0 to 4) The damage will affect the defender’s health. If the defender’s health ≤ 0, they are removed from their BST immediately. The next combatant automatically takes their
place as the new frontline fighter.
During each turn, the game must display the following information clearly:
 Round number
 Names and current HP of all heroes and enemies (in BST order)
 Active attackers and defenders
 Damage dealt in the attack
 Updated HP values after each hit
 Elimination messages when a combatant is defeated
 Victory message when one BST becomes empty*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int health;
    int attackPower;
    
    Combatant(string n, int h, int a) : name(n), health(h), attackPower(a) {}
    
    bool operator<(const Combatant& other) const {
        return name < other.name;
    }
    
    bool operator>(const Combatant& other) const {
        return name > other.name;
    }
    
    bool operator==(const Combatant& other) const {
        return name == other.name;
    }
};

class Node {
public:
    Combatant data;
    Node* left;
    Node* right;

    Node(Combatant val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, Combatant val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (root->data > val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, Combatant target) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == target) {
        return true;
    }
    if (root->data > target) {
        return search(root->left, target);
    }
    else {
        return search(root->right, target);
    }
}

Node* minNode(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, Combatant val) {
    if (root == nullptr) {
        return root;
    }
    else if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data.name << " (HP: " << root->data.health << ") ";
    inOrder(root->right);
}

Node* getFrontline(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

bool isDefeated(Node* root) {
    return root == nullptr;
}

int calcDamage(int baseAttack) {
    return baseAttack + (rand() % 5); 
}

void displayTeams(Node* playerTeam, Node* enemyTeam, int round) {
    cout << "Round " << round << endl;
    cout << "Heroes: ";
    inOrder(playerTeam);
    cout << endl;
    
    cout << "Enemies: ";
    inOrder(enemyTeam);
    cout << endl;
}

void battle(Node*& playerTeam, Node*& enemyTeam) {
    srand(time(0)); 
    int round = 1;
    Combatant heroes[5] = { Combatant("percy", 30, 25), Combatant("harry", 25, 10), Combatant("annabeth", 35, 15), Combatant("hermoine", 28, 9), Combatant("grover", 32, 8) };
    Combatant enemies[5] = { Combatant("voldemort", 20, 6), Combatant("kronos", 40, 5), Combatant("giant", 15, 8), Combatant("bellatrix", 50, 12), Combatant("zeus", 18, 10) };
    
    for (int i = 0; i < 5; i++) {
        playerTeam = insert(playerTeam, heroes[i]);
        enemyTeam = insert(enemyTeam, enemies[i]);
    }
    
    cout << "BattleQuest: BST Arena" << endl;
    cout << "Teams:" << endl;
    displayTeams(playerTeam, enemyTeam, 0);
    cout << endl << "start" << endl;
    while (!isDefeated(playerTeam) && !isDefeated(enemyTeam)) {
        displayTeams(playerTeam, enemyTeam, round);
        Node* playerFrontline = getFrontline(playerTeam);
        Node* enemyFrontline = getFrontline(enemyTeam);
        if (playerFrontline && enemyFrontline) {
            int damage = calcDamage(playerFrontline->data.attackPower);
            cout << "hero's turn " << endl;
            cout << playerFrontline->data.name << " attacks " << enemyFrontline->data.name << endl;
            cout << "damage givem: " << damage << endl;
            
            enemyFrontline->data.health -= damage;
            cout << enemyFrontline->data.name << "'s hp: " << enemyFrontline->data.health + damage 
                 << " -> " << enemyFrontline->data.health << endl;

            if (enemyFrontline->data.health <= 0) {
                cout << enemyFrontline->data.name << " has been defeated" << endl;
                enemyTeam = deleteNode(enemyTeam, enemyFrontline->data);
            }
        }
        
        if (isDefeated(enemyTeam)) {
            break;
        }
        playerFrontline = getFrontline(playerTeam);
        enemyFrontline = getFrontline(enemyTeam);
        
        if (playerFrontline && enemyFrontline) {
            int damage = calcDamage(enemyFrontline->data.attackPower);
            
            cout << "enemy's turn " << endl;
            cout << enemyFrontline->data.name << " attacks " << playerFrontline->data.name << endl;
            cout << "damage given: " << damage << endl;
            
            playerFrontline->data.health -= damage;
            cout << playerFrontline->data.name << "'s hp: " << playerFrontline->data.health + damage 
                 << " -> " << playerFrontline->data.health << endl;
            
            if (playerFrontline->data.health <= 0) {
                cout << playerFrontline->data.name << " has been defeated" << endl;
                playerTeam = deleteNode(playerTeam, playerFrontline->data);
            }
        }
        
        round++;
        cout << endl;
    }
    
    cout << endl << "final result" << endl;
    if (isDefeated(playerTeam)) {
        cout << "you lost" << endl;
    } 
    else {
        cout << "you won" << endl;
    }
    
    cout << "total rounds: " << round - 1 << endl;
}

int main() {
    Node* playerTeam = nullptr;
    Node* enemyTeam = nullptr;
    battle(playerTeam, enemyTeam);
}
