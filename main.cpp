#include <iostream>
#include <vector>
#include <algorithm>

class Texture {
public:
	Texture(const std::string& filename) {
		//Logic to load a texture from a file
		std::cout << "Textura Cargada desde: " << filename << std::endl;
	}
	~Texture() {
		//Logic to release resources associate to the texture

		std::cout << "Textura liberda." << std::endl;
	}

};

class TextureManager {
private:
	std::vector<Texture*> loadedTextures;

public:
	Texture* LoadTexture(const std::string& filename) {
		Texture* pTexture = new Texture(filename);
		loadedTextures.push_back(pTexture);
		return pTexture;
	}

	void UnloadTexture(Texture* pTexture) {
		auto it = std::find(loadedTextures.begin(), loadedTextures.end(), pTexture);
		if (it != loadedTextures.end()) {
			delete pTexture;
			loadedTextures.erase(it);
			std::cout << "Textura eliminada correctamente" << std::endl;
		}
		else {
			std::cout << "No se encontro la textura " << std::endl;
		}
	} 

	~TextureManager() {
		for (auto pTexture : loadedTextures) {
			delete pTexture;
		}

		loadedTextures.clear();
	}

};

int main() {
	TextureManager textureManager;

	//Use

	Texture* textureWall = textureManager.LoadTexture("Wall.png");
	Texture* textureWater = textureManager.LoadTexture("Water.png");
	Texture* textureLand = textureManager.LoadTexture("Land.png");
	Texture* textureFungi = new Texture("fungi.png");

	
	textureManager.UnloadTexture(textureWall);
	textureManager.UnloadTexture(textureLand);
	textureManager.UnloadTexture(textureFungi);

	return 0;
}