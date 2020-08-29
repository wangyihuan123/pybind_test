import cv2
import example


print(cv2.__version__)

image_file = "./data/1540417820.jpg"
image = example.read_image(image_file)
print(image.shape)

img = cv2.imread(image_file)
print(img.shape)
print(example.wangyidong(img))
print(example.detect(img))
print(example.tkdnnDetect(img))
