#include "Game.h"
#include "assets/levels.h"
#include "assets/sprites.h"

void Game::begin() {

    _framebuffer = new LGFX_Sprite(&espboy.tft);
    _framebuffer->createSprite(TFT_WIDTH, TFT_HEIGHT);

    _level = 1;
    
    _player.begin(_level);
    
}

void Game::loop() {

    _readButtons();
    _update();
    _draw();

}

void Game::_readButtons() {

    if (espboy.button.pressed(Button::LEFT)) {

        _player.runToLeft();

    } else if (espboy.button.pressed(Button::RIGHT)) {

        _player.runToRight();

    } else if (
        espboy.button.released(Button::LEFT) ||
        espboy.button.released(Button::RIGHT)
    ) {

        _player.stop();

    }
    
    if (espboy.button.held(Button::UP)) {

        _player.flyUp();

    } else if (espboy.button.held(Button::DOWN)) {

        _player.flyDown();

    }

    if (espboy.button.held(Button::TOP_LEFT)) {

        _previousLevel();

    } else if (espboy.button.held(Button::TOP_RIGHT)) {

        _nextLevel();

    }

}

void Game::_update() {

    _player.update();

    _camera.follow(
        _player.x() - ((TFT_WIDTH  - PLAYER_WIDTH)  >> 1),
        _player.y() - ((TFT_HEIGHT - PLAYER_HEIGHT) >> 1)
    );

}

void Game::_draw() {

    _framebuffer->clear();

    _map.draw(_level, _camera, _framebuffer);
    _player.draw(_camera, _framebuffer);

    _framebuffer->pushSprite(0, 0);

}

void Game::_previousLevel() { if (_level > 1)            _player.begin(--_level); }
void Game::_nextLevel()     { if (_level < LEVEL_NUMBER) _player.begin(++_level); }

/**
 * ----------------------------------------------------------------------------
 * Lode Runner game bootstrap
 * ----------------------------------------------------------------------------
 * Copyright (c) 2022 Stéphane Calderoni (https://github.com/m1cr0lab)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 * ----------------------------------------------------------------------------
 */