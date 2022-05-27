#include "Player.h"
#include "assets/levels.h"
#include "assets/tileset.h"
#include "assets/sprites.h"

void Player::begin(uint8_t const level) {

    uint16_t const offset = (level - 1) << 1;

    _state = State::STAND_BY;
    _x     = TILE_LENGTH * LEVEL_PLAYER_START[offset];
    _y     = TILE_LENGTH * LEVEL_PLAYER_START[offset + 1];
    _vx    = 0;
    _vy    = 0;
    _frame = 0;

}

uint16_t const Player::x() const { return _x; }
uint16_t const Player::y() const { return _y; }

void Player::stop() {

    _state = State::STAND_BY;
    _vx    = 0;
    _frame = PLAYER_STAND_BY_FRAME;

}

void Player::runToLeft() {

    _state = State::RUN;
    _vx    = -1;
    _frame = PLAYER_RUN_START_FRAME;
    
}

void Player::runToRight() {

    _state = State::RUN;
    _vx    = 1;
    _frame = PLAYER_RUN_START_FRAME;

}

void Player::flyUp() {

    if (_y > 0) _y--;

}

void Player::flyDown() {

    if (_y + PLAYER_HEIGHT < LEVEL_HEIGHT * TILE_LENGTH) _y++;

}

void Player::update() {

    if (
        (_vx < 0 && _x + _vx >= 0) ||
        (_vx > 0 && _x + PLAYER_WIDTH + _vx < LEVEL_WIDTH * TILE_LENGTH)
    ) {

        _x += _vx;

    }

    if (
        (_vy < 0 && _y + _vy >= 0) ||
        (_vy > 0 && _y + PLAYER_HEIGHT + _vy < LEVEL_HEIGHT * TILE_LENGTH)
    ) {

        _y += _vy;

    }

    switch (_state) {

        case State::RUN:
        
            static uint8_t       counter     = 0;
            static uint8_t const start_frame = PLAYER_RUN_START_FRAME;
            static uint8_t const end_frame   = PLAYER_RUN_START_FRAME + PLAYER_RUN_FRAMES;
            
            if (++counter > 5) {
                counter = 0;
                _frame++; if (_frame < end_frame) return;
                _frame = start_frame;
            }
            
            break;
        
        default:;

    }

}

void Player::draw(Camera const &camera, LGFX_Sprite *framebuffer) {

    bool const to_the_left = _vx < 0;

    framebuffer->pushImageRotateZoom(
        _x + (to_the_left ? PLAYER_WIDTH : 0) - camera.x,
        _y - camera.y,
        0,
        0,
        0,
        to_the_left ? -1 : 1, 1,
        PLAYER_WIDTH,
        PLAYER_HEIGHT,
        PLAYER + _frame * PLAYER_SIZE,
        TRANS_COLOR
    );

}

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