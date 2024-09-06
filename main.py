from shapes import get_shape_list

if __name__ == "__main__":
    shapes = get_shape_list()
    for shape in shapes:
      print(shape.get_name())
      print(shape.calculate_area())
