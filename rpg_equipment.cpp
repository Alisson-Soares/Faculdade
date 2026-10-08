//
// Created by tarben on 05/10/2026.
//
/**
 * Somente a elaboração do exercicio base foi feito por IA
 *
 * @file rpg_equipment.cpp
 * @brief Desafio de RPG: Sistema de Equipamento e Dano (LearnCpp Cap. 12 & 13)
 *
 * @details Este programa implementa um mini-sistema de gerenciamento de itens
 * e personagens, aplicando conceitos fundamentais do C++ moderno:
 * - Uso de 'enum class' (scoped enums) para definir raridades com segurança de tipos.
 * - Criação de 'structs' (Weapon e Player) utilizando inicialização agregada.
 * - Gerenciamento de estado opcional com ponteiros crus (Weapon*) permitindo
 *   que um personagem esteja desarmado (nullptr).
 * - Uso de 'std::optional<double>' para o cálculo seguro de dano condicional.
 * - Passagem de parâmetros por referência para evitar cópias desnecessárias.
 */

#include <iostream>
#include <string>
#include <string_view>
#include <optional>
enum class Rarity {
    Common,
    Rare,
    Epic,
    Legendary,
};

struct Weapon {
    std::string name{};
    float damage{};
    Rarity rarity{};
};

struct Player {
    std::string name{};
    Weapon* weapon{};
};

std::ostream& operator<<(std::ostream& os, const Rarity& r) {
    switch (r) {
        case::Rarity::Common: os << "Common"; break;
        case::Rarity::Rare: os << "Rare"; break;
        case::Rarity::Epic: os << "Epic"; break;
        case::Rarity::Legendary: os << "Legendary"; break;
    }
    return os;
}

void equip_weapon(Player& player, Weapon* weapon) {
    if (!weapon)
        {std::cout << "Erro: arma não existe." << std::endl;}
    player.weapon = weapon;
    std::cout << "O " << player.name << " trocou de arma para a " << player.weapon->name << "." << std::endl;
}

std::optional<double>getAttackDamage(const Player& player) {
    if (player.weapon)
        {return std::nullopt;}
    return player.weapon->damage;
}

void printPlayerStatus(const Player& player) {

    std::cout << "Player: " << player.name << std::endl;
    if (player.weapon) {
        std::cout << "Arma:" << player.weapon->name << std::endl
        << "Rarity:" << player.weapon->rarity << std::endl
        << "Damage: " << player.weapon->damage << std::endl;
    }
}

int main() {

    Weapon espada{"Espada Reta", 75, Rarity::Epic};
    Weapon machado{"Machado Pesado", 250, Rarity::Legendary};

    // Criando o jogador já desarmado por padrão
    Player player{"Gerso", nullptr};

    printPlayerStatus(player);

    // Como as armas não foram criadas com 'new', passamos o endereço delas usando '&'
    equip_weapon(player, &espada);

    printPlayerStatus(player);
}