from __future__ import absolute_import, division, print_function, unicode_literals

# Install TensorFlow

import tensorflow as tf

mnist = tf.keras.datasets.mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0

model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(input_shape=(28, 28)),
  tf.keras.layers.Dense(128, activation='relu'),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5)

model.evaluate(x_test,  y_test, verbose=2)

# sajat kepekkel: 4 = 7, 8 = 3, 9 = 1, 1 = 1 hurrááááá néha 3, 7 = 7, 8 = 3, 8 = 8/6/2, 5=3, villam4 = 4/6

from matplotlib.image import imread # sajat kephez
import numpy as np # sajat kephez

img = imread('eght.png') # csak png-t hasznalj, az RGB értékek 0 és 1 között vannak, így nincs szükség elosztani őket 255-el

img_gray = 1 - img[:, :, 0] # mivel a kép fekete-fehér, ezért mind az R, G és B érték ugyanaz, így elég csak az egyiket elmenteni, mert az algoritmus 28 * 28-as formátumot igényel (és nem 28*28*4(RGBA))
testimg = np.array([img_gray]) # a predict függvénynek numpy array-ba helyezett képek kellenek, ezért mi beletesszük a miénket
predicts = model.predict(testimg) # megkérjük a model hogy tippelje meg h mit irhattunk a kepekre (nekünk csak 1 van most) és mentse el a predicts valtozozba tömbként (pl. [szerintem8, talán7, biztos3])
print("sajat kep: ")
print( np.argmax(predicts[0]) )
""" megnézzük hogy az elso (nulladik) képre mit tippelt. Ehhez szükség van az argmax függvényre, mert a model 10 értéket ad vissza egy kép tippelésekor (pl. szerinte ez 10%-ra 1-es, 20%-ra 2-es...), de nekünk csak a legnagyobb kell, amiben a legbiztosabb """
