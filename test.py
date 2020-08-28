from build import example
import cv2

print(cv2.__version__)

image_file = "/home/benwang/data/test_data/mini/1540417820.jpg"
image = example.read_image(image_file)
print(image.shape)

img = cv2.imread(image_file)
print(img.shape)
print(example.wangyidong(img))