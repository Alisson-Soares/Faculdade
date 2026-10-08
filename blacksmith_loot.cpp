//
// Created by tarben on 07/10/2026.
//
/** Somente o exercicio base foi efeito utilizando IA
 *
 * @file blacksmith_loot.cpp
 * @brief Sistema de Loot e Ferreiro (Ponteiros Nulos e Passagem por Referência)
 *
 * @details Explora a diferenciação prática entre ponteiros e referências em C++:
 * - Função de busca (findMostValuable) utilizando ponteiros (Item*) para lidar
 *   com a possibilidade de itens nulos (nullptr).
 * - Tratamento de segurança validando ponteiros antes do acesso à memória.
 * - Função de aprimoramento (upgradeItem) exigindo obrigatoriamente um objeto
 *   válido através de referência (Item&).
 * - Desreferenciação de ponteiros (*best_item) para interagir com funções que
 *   exigem referências.
 */

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

enum class Rarity {
    Common,
    Rare,
    Epic,
    Legendary,
};

struct Item {
    std::string name{};
    Rarity rarity{};
    float price{};
};

void upgradeItem(Item& item) {
    item.name += "+";
    if (item.price >= 0)
        {item.price *= 1.5;}
    else
        {item.price = 100.f;}
}

Item* findMostValuable(Item* a, Item* b, Item* c) {
    std::vector<Item*> itens{};
    if (a){itens.push_back(a);}
    if (b){itens.push_back(b);}
    if (c){itens.push_back(c);}
    if (itens.empty()) {return nullptr;}

    Item* valuabler{itens[0]};
    for (int i = 1; i < itens.size(); i++) {
        if (valuabler->price < itens[i]->price) {
            valuabler = itens[i];
        }
    }
    return valuabler;
}
int main() {
    Item a{.name = "a", .rarity = Rarity::Common, .price = 50};
    Item b{.name = "b", .rarity = Rarity::Epic, .price = 500};
    Item c{.name = "c", .rarity = Rarity::Legendary, .price = 50'000};

    Item* ptr_a = &a;
    Item* ptr_b = &b;
    Item* ptr_c = &c;

    Item* best_item = findMostValuable(ptr_a,ptr_b,ptr_c);
    if (best_item == nullptr) {std::cout << "Dont exist any Item." << std::endl;}

    std::cout << best_item->name << std::endl;

}
