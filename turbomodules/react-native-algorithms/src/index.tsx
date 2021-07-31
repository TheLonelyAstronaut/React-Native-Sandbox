import { NativeModules } from 'react-native';

type AlgorithmsType = {
  multiply(a: number, b: number): Promise<number>;
};

const { Algorithms } = NativeModules;

export default Algorithms as AlgorithmsType;
