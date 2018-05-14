#include "Map.hpp"
#include "Game.hpp"

bool Map::Parse(char c, int *result) {
	if (c >= '0' && c <= '9') {
		*result = c - '0';
		return true;
	}
	return false;
}

bool Map::ParseUntil(std::fstream *stream, char sep, int *result) {
	char c;
	int total = 0, res;

	do {
		stream->get(c);
		if (Parse(c, &res)) {
			total = total * 10 + res;
		} else {
			break;
		}
	} while (c != sep);

	*result = total;

	return true;
}

void Map::Load(const char *path) {
	char tile;
	std::fstream stream;
	stream.open(path);

	int i, width, height;

	if (ParseUntil(&stream, ',', &width) && ParseUntil(&stream, '\n', &height)) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				stream.get(tile);

				if (Parse(tile, &i)) {
					Game::AddTile(x, y, i);
				}

				stream.ignore();
			}
			stream.ignore();
		}
	}

	stream.close();
}
