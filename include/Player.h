#pragma once

#include <ESPboy.h>
#include "Camera.h"

class Player {

    public:

        void begin(uint8_t const level);

        uint16_t const x() const;
        uint16_t const y() const;

        void stop();
        void runToLeft();
        void runToRight();
        void flyUp();
        void flyDown();

        void update();
        void draw(Camera const &camera, LGFX_Sprite *framebuffer);

    private:

        enum class State : uint8_t {
            STAND_BY,
            RUN
        };
    
        State    _state;
        uint16_t _x;
        uint16_t _y;
        int8_t   _vx;
        int8_t   _vy;
        uint8_t  _frame;

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