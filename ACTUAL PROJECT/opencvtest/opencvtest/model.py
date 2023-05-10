import tensorflow as tf;
from tensorflow.keras.layers import Input, Conv2D, MaxPooling2D, Flatten, Dense
from tensorflow.keras.models import Model
from tensorflow.keras.optimizers import Adam

# Define the input shape of the CNN
input_shape = (224, 224, 1)

# Define the CNN architecture
input_layer = Input(shape=input_shape, name='input')
conv_layer1 = Conv2D(32, (3, 3), activation='relu', padding='same')(input_layer)
pooling_layer1 = MaxPooling2D((2, 2))(conv_layer1)
conv_layer2 = Conv2D(64, (3, 3), activation='relu', padding='same')(pooling_layer1)
pooling_layer2 = MaxPooling2D((2, 2))(conv_layer2)
flatten_layer = Flatten()(pooling_layer2)
dense_layer1 = Dense(128, activation='relu')(flatten_layer)
output_layer = Dense(1, activation='sigmoid', name='output')(dense_layer1)

# Define the CNN model
model = Model(inputs=input_layer, outputs=output_layer)

# Compile the model with an optimizer and loss function
model.compile(optimizer=Adam(lr=0.001), loss='binary_crossentropy', metrics=['accuracy'])

# Train the model on your dataset
# ...

# Save the model in TensorFlow format
tf.keras.models.save_model(model, 'model.pb', save_format='tf')