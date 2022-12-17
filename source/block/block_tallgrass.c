/*
	Copyright (c) 2022 ByteBit/xtreme8000

	This file is part of CavEX.

	CavEX is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	CavEX is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with CavEX.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "blocks.h"

static enum block_material getMaterial(struct block_info* this) {
	return MATERIAL_ORGANIC;
}

static bool getBoundingBox(struct block_info* this, bool entity,
						   struct AABB* x) {
	aabb_setsize(x, 0.8125F, 0.8125F, 0.8125F);
	return !entity;
}

static struct face_occlusion*
getSideMask(struct block_info* this, enum side side, struct block_info* it) {
	return face_occlusion_empty();
}

static enum block_render_type getRenderType(struct block_info* this) {
	return RENDERTYPE_CROSS;
}

static uint8_t getTextureIndex1(struct block_info* this, enum side side) {
	switch(this->block->metadata) {
		case 1: return TEXTURE_INDEX(5, 12); // tallgrass
		case 2: return TEXTURE_INDEX(5, 13); // fern
		default: return TEXTURE_INDEX(6, 3); // deadbush
	}
}

static uint8_t getTextureIndex2(struct block_info* this, enum side side) {
	return TEXTURE_INDEX(6, 3); // deadbush
}

static uint32_t getBaseColor(struct block_info* this, enum side side) {
	return (this->block->metadata == 0) ? 0xFFFFFF : 0x619961;
}

struct block block_tallgrass = {
	.name = "Tallgrass",
	.getRenderType = getRenderType,
	.getSideMask = getSideMask,
	.getBoundingBox = getBoundingBox,
	.getMaterial = getMaterial,
	.getTextureIndex = getTextureIndex1,
	.transparent = false,
	.getBaseColor = getBaseColor,
	.renderBlock = render_block_cross,
	.renderBlockAlways = NULL,
	.luminance = 0,
	.double_sided = true,
	.can_see_through = true,
	.render_block_data.cross_random_displacement = true,
	.ignore_lighting = false,
	.flammable = true,
};

struct block block_deadbush = {
	.name = "Deadbush",
	.getRenderType = getRenderType,
	.getSideMask = getSideMask,
	.getBoundingBox = getBoundingBox,
	.getMaterial = getMaterial,
	.getTextureIndex = getTextureIndex2,
	.transparent = false,
	.getBaseColor = getBaseColor,
	.renderBlock = render_block_cross,
	.renderBlockAlways = NULL,
	.luminance = 0,
	.double_sided = true,
	.can_see_through = true,
	.render_block_data.cross_random_displacement = false,
	.ignore_lighting = false,
	.flammable = true,
};
