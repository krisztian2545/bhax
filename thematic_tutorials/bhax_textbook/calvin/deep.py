from __future__ import absolute_import, division, print_function, unicode_literals

# Install TensorFlow

import tensorflow as tf
import matplotlib.pyplot as plt
from matplotlib.image import imread
import numpy as np

mnist = tf.keras.datasets.mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()

x_train = x_train.reshape(x_train.shape[0], 28, 28, 1)
x_test = x_test.reshape(x_test.shape[0], 28, 28, 1)
input_shape = (28, 28, 1)

x_train = x_train.astype('float32')
x_test = x_test.astype('float32')

x_train, x_test = x_train / 255.0, x_test / 255.0

model = tf.keras.models.Sequential([
  tf.keras.layers.Conv2D(32, kernel_size=(5, 5), padding="same", activation='relu', input_shape=input_shape),
  tf.keras.layers.MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding="same"),
  tf.keras.layers.Conv2D(64, kernel_size=(5, 5), padding="same", activation='relu'),
  tf.keras.layers.MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding="same"),
  tf.keras.layers.Flatten(),
  tf.keras.layers.Dense(1024, activation='relu'),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

model.fit(x_train, y_train, epochs=3)

model.evaluate(x_test,  y_test, verbose=2)

model.summary()

plt.imshow(x_test[4444].reshape(28, 28),cmap='Greys')
pred = model.predict(x_test[4444].reshape(1, 28, 28, 1))
print(pred.argmax())
plt.show()

# sajat kepekkel: 4 = 4, 1 = 1, 2 = 2 perfect

img = imread('eght.png') # csak png-t hasznalj, az RGB értékek 0 és 1 között vannak, így nincs szükség elosztani őket 255-el
img_gray = 1 - img[:, :, 0]
testimg = np.array([img_gray]) # a predict függvénynek numpy array-ba helyezett képek kellenek, ezért mi beletesszük a miénket
predicts = model.predict(testimg[0].reshape(1, 28, 28, 1)) # megkérjük a model hogy tippelje meg h mit irhattunk a kepekre (nekünk csak 1 van most) és mentse el a predicts valtozozba tömbként (pl. [szerintem8, talán7, biztos nem3])
print("sajat kep: ")
print( np.argmax(predicts[0]) )
