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
	return MATERIAL_WOOD;
}

static bool getBoundingBox(struct block_info* this, bool entity,
						   struct AABB* x) {
	aabb_setsize(x, 0.3125F, 0.625F, 0.3125F);

	switch(this->block->metadata) {
		case 1: aabb_translate(x, -0.34375F, 0.1875F, 0); break;
		case 2: aabb_translate(x, 0.34375F, 0.1875F, 0); break;
		case 3: aabb_translate(x, 0, 0.1875F, -0.34375F); break;
		case 4: aabb_translate(x, 0, 0.1875F, 0.34375F); break;
		default: aabb_setsize(x, 0.2F, 0.6F, 0.2F); break;
	}

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
	return TEXTURE_INDEX(0, 5);
}

static uint8_t getTextureIndex2(struct block_info* this, enum side side) {
	return TEXTURE_INDEX(3, 7);
}

static uint8_t getTextureIndex3(struct block_info* this, enum side side) {
	return TEXTURE_INDEX(3, 6);
}

static uint32_t getBaseColor(struct block_info* this, enum side side) {
	return 0xFFFFFF;
}

struct block block_torch = {
	.name = "Torch",
	.getRenderType = getRenderType,
	.getSideMask = getSideMask,
	.getBoundingBox = getBoundingBox,
	.getMaterial = getMaterial,
	.getTextureIndex = getTextureIndex1,
	.transparent = false,
	.getBaseColor = getBaseColor,
	.renderBlock = render_block_torch,
	.renderBlockAlways = NULL,
	.luminance = 14,
	.double_sided = false,
	.can_see_through = true,
	.ignore_lighting = false,
	.flammable = false,
};

struct block block_redstone_torch = {
	.name = "Redstone Torch",
	.getRenderType = getRenderType,
	.getSideMask = getSideMask,
	.getBoundingBox = getBoundingBox,
	.getMaterial = getMaterial,
	.getTextureIndex = getTextureIndex2,
	.transparent = false,
	.getBaseColor = getBaseColor,
	.renderBlock = render_block_torch,
	.renderBlockAlways = NULL,
	.luminance = 0,
	.double_sided = false,
	.can_see_through = true,
	.ignore_lighting = false,
	.flammable = false,
};

struct block block_redstone_torch_lit = {
	.name = "Redstone Torch",
	.getRenderType = getRenderType,
	.getSideMask = getSideMask,
	.getBoundingBox = getBoundingBox,
	.getMaterial = getMaterial,
	.getTextureIndex = getTextureIndex3,
	.transparent = false,
	.getBaseColor = getBaseColor,
	.renderBlock = render_block_torch,
	.renderBlockAlways = NULL,
	.luminance = 7,
	.double_sided = false,
	.can_see_through = true,
	.ignore_lighting = false,
	.flammable = false,
};
