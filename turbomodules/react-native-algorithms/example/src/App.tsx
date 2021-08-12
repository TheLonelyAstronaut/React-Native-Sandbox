import * as React from 'react';

import { StyleSheet, View, Button, Alert } from 'react-native';
import Algorithms from 'react-native-algorithms';

export default function App() {
  return (
    <View style={styles.container}>
      <Button
        title={'Get result'}
        onPress={() => Alert.alert(Algorithms.getShortestGraphPath())}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
