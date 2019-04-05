// TODO - Sound system
#include "systems.hpp"
#include <SFML/Audio.hpp>

void soundHandler(State& state, sf::Keyboard Keyboard ) {
  for(vector<Entity>::iterator it = state.entities.begin(); it != state.entities.end(); ++it) {
    if(it->hasSound){
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        it->sound.play();
        it->sound.setPlayingOffset(sf::seconds(2.f));

      }
    }
  }
}
