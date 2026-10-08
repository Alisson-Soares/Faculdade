//
// Created by tarben on 07/10/2026.
//
//Somente a elaboração do exercicio base foi feito por IA
/**
 *
 * @file game_settings.cpp
 * @brief Gerenciador de Configurações de Jogo via Designated Initializers (C++20)
 *
 * @details Demonstra o uso de recursos modernos do C++20 aplicados a structs:
 * - Aplicação de valores padrão em membros de estruturas (Member Initializers).
 * - Uso de Inicializadores Designados (.membro = valor) para instanciar objetos
 *   alterando apenas os campos desejados e herdando o restante por padrão.
 * - Sobrecarga do operador de inserção de fluxo (operator<<) para formatar a
 *   impressão de structs customizadas.
 * - Utilização de 'std::boolalpha' para exibir booleanos legíveis ("true"/"false")
 *   no console.
 */
#include <iostream>
#include <string>

struct GameSetting {
    std::string name;
    int width{1680};
    int height{1280};
    float volume{1.0f};
    bool fullscreen{false};
    bool vsync{false};
};

std::ostream& operator<<(std::ostream& os, const GameSetting& gameSetting) {
    os << gameSetting.name << std::endl
    << gameSetting.width << " "<< gameSetting.height << std::endl
    << gameSetting.volume << " " << std::endl
    << std::boolalpha
    << gameSetting.fullscreen << " "<< gameSetting.vsync << std::endl;
    return os;
}

int main() {
    GameSetting lowsetting{
        .name = "low Window", .width = 640, .height = 480, .volume = 1.0f,
        .fullscreen = false, .vsync = false};

    GameSetting standardsetting{};

    GameSetting highsetting{
        .name = " High Window", .width = 1920, .height = 1200, .volume = 1.0f,
        .fullscreen = true, .vsync = true};
    std::cout <<lowsetting << std::endl;
    std::cout <<standardsetting << std::endl;
    std::cout <<highsetting << std::endl;


}