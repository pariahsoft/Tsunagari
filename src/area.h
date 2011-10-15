/******************************
** Tsunagari Tile Engine     **
** area.h                    **
** Copyright 2011 OmegaSDG   **
******************************/

#ifndef AREA_H
#define AREA_H

#include <string>
#include <vector>

#include <boost/scoped_ptr.hpp>
#include <Gosu/Graphics.hpp> // for Gosu::Transform

#include "common.h"
#include "music.h"
#include "player.h"
#include "resourcer.h"
#include "tile.h"
#include "xml.h"

namespace Gosu {
	class Bitmap;
	class Button;
	class Image;
}

class Entity;
class GameWindow;
class Music;
class Resourcer;
class Sprite;
class World;

//! This class is responsible for each map, or area in a Tsunagari World.
/*!
	The Area class handles the parsing of TMX-format Area descriptor files, 
	the initialization, placement, and drawing of tiles, and various 
	Area-related functionality.
*/
class Area
{
public:
	//! Area Constructor
	Area(Resourcer* rc, World* world, Player* player, Music* music,
			const std::string& filename);

	//! Area Destructor
	~Area();

	//! Function that must be called after the constructor.
	bool init();

	//! Gosu Callback
	void buttonDown(const Gosu::Button btn);
	void buttonUp(const Gosu::Button btn);

	//! Gosu Callback
	void draw();

	//! Gosu Callback
	bool needsRedraw() const;

	//! Gosu Callback
	void update(unsigned long dt);

	icoord getDimensions() const;
	icoord getTileDimensions() const;
	const Tile& getTile(icoord c) const;
	Tile& getTile(icoord c);
	icube_t visibleTiles() const;

private:
	//! Calculate frame to show for each type of tile
	void updateTileAnimations();
	void drawTiles() const;
	void drawTile(const Tile& tile, int x, int y, int z) const;
	void drawEntities();

	const icoord viewportOffset() const;
	const Gosu::Transform viewportTransform() const;

	//! XML descriptor parsing function.
	bool processDescriptor();

	//! XML descriptor parsing function.
	bool processMapProperties(XMLNode node);

	//! XML descriptor parsing function.
	bool processTileSet(XMLNode node);

	//! Constructs a tile of default type.
	TileType defaultTileType(TileSet& set);

	//! XML descriptor parsing function.
	bool processTileType(XMLNode node, TileSet& ts);

	//! XML descriptor parsing function.
	bool processLayer(XMLNode node);

	//! XML descriptor parsing function.
	bool processLayerProperties(XMLNode node);

	//! XML descriptor parsing function.
	bool processLayerData(XMLNode node);

	//! XML descriptor parsing function.
	bool processObjectGroup(XMLNode node);

	//! XML descriptor parsing function.
	bool processObjectGroupProperties(XMLNode node, int* zpos);

	//! XML descriptor parsing function.
	bool processObject(XMLNode node, int zpos);

	//! Split a tile's flags into individuals.
	unsigned splitTileFlags(const std::string strOfFlags);

	//! Process a door convenience trigger.
	Door parseDoor(const std::string dest);

	Resourcer* rc;
	World* world;
	Player* player;
	Music* music;
	const std::string descriptor;

	typedef std::vector<Tile> row_t;
	typedef std::vector<row_t> grid_t;
	typedef std::vector<grid_t> tilematrix_t;

	/* All layers in the map must be in the range of [0, n]. There cannot be
	 * any gaps.
	 */
	tilematrix_t map;
	icoord dim;

	std::string name;
	std::string author;
	std::vector<TileSet> tilesets;
	std::string scripts;
	std::string onLoadEvents;
};

#endif

