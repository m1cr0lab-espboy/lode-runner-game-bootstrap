#include <ESPboy.h>
#include "Camera.h"
#include "assets/levels.h"
#include "assets/tileset.h"

void Camera::follow(int16_t const x, int16_t const y) {

    uint16_t const w = LEVEL_WIDTH  * TILE_LENGTH - TFT_WIDTH;
    uint16_t const h = LEVEL_HEIGHT * TILE_LENGTH - TFT_HEIGHT;

    if (x < 0) {
        this->x = 0;
    } else if (x >= w) {
        this->x = w;
    } else {
        this->x = x;
    }

    if (y < 0) {
        this->y = 0;
    } else if (y >= h) {
        this->y = h;
    } else {
        this->y = y;
    }

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