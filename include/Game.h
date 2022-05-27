#pragma once

#include <ESPboy.h>
#include "Camera.h"
#include "TileMap.h"
#include "Player.h"

class Game {

    public:

        void begin();
        void loop();
    
    private:

        LGFX_Sprite *_framebuffer;
        Camera       _camera;
        TileMap      _map;
        Player       _player;

        uint8_t _level;

        void _readButtons();
        void _update();
        void _draw();

        void _previousLevel();
        void _nextLevel();

};

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