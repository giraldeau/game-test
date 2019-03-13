vector<Physics> handlePhysics(vector<Physics>, float time) {
  for(std::vector<Physics>::iterator it = v.begin(); it != v.end(); ++it) {
    *it.velocity.x += accelaration.x * time;
    *it.velocity.y += acceleration.y * time;
    *it.velocity.x += friction * time;
    *it.velocity.y += friction * time;
    *it.position.x += velocity.x * time;
    *it.position.y += velocity.y * time;
}
}
