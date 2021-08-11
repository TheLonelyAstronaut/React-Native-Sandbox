//import { NativeModules } from 'react-native';

declare function getShortestGraphPath(): string;

type AlgorithmsType = {
  getShortestGraphPath(): string;
};

//const { Algorithms } = NativeModules;

//const _module = Algorithms as AlgorithmsType;

//_module.getShortestGraphPath = getShortestGraphPath;

export default {
  getShortestGraphPath
} as AlgorithmsType;
