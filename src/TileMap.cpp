#include "TileMap.h"
#include "assets/levels.h"
#include "assets/tileset.h"

void TileMap::draw(uint8_t const level, Camera const &camera, LGFX_Sprite * const framebuffer) {

    uint32_t const offset = (level - 1) * LEVEL_SIZE;
    uint8_t        tile;
    int8_t         x, y;
    
    for (uint8_t i = 0; i < LEVEL_HEIGHT; ++i) {
        for (uint8_t j = 0; j < LEVEL_WIDTH; ++j) {

            tile = pgm_read_byte(LEVEL_MAP + offset + i * LEVEL_WIDTH + j);
            x    = j * TILE_LENGTH - camera.x;
            y    = i * TILE_LENGTH - camera.y;

            if (
                tile                &&
                x + TILE_LENGTH > 0 &&
                x < TFT_WIDTH       &&
                y + TILE_LENGTH > 0 &&
                y < TFT_HEIGHT
            ) {
                framebuffer->pushImage(
                    x,
                    y,
                    TILE_LENGTH,
                    TILE_LENGTH,
                    TILESET + (tile - 1) * TILE_SIZE
                );
            }

        }
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