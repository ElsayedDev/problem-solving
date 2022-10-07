class Person {}

class Sweed extends Person {
  void _lead() {
    // handle tech
    // handle xyz
  }

  void teach() {}

  void xyz() {}
}

class XyzMardy extends Sweed {
  @override
  void teach() {
    super.teach();
  }
}

class XyzKhaled extends Sweed {
  @override
  void xyz() {
    super.xyz();
  }
}

class XyzSetven extends Sweed {
  @override
  void xyz() {
    super.xyz();
  }
}

class Ahmed {
  lead() {
    final ob = Sweed();

    ob._lead();
    ob.teach();
    ob.xyz();
  }
}
