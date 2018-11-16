import React from 'react';
import {
  StyleSheet,
  View,
  StatusBar,
  Text,
  TextInput,
  Alert,
  TouchableOpacity,

} from 'react-native';

//to navigate multiple pages

export default class Settings extends React.Component {
  onButtonPress(){
    Alert.alert("Your account settings have been saved.");
  }
  constructor(props) {
    super(props);
    this.state = {text: ''};
  }

  render() {
    return (
      <View  style={styles.container}>
        <View style={styles.secondContainer}>
            <TextInput
              style={styles.inputBox}
              placeholder = 'user.username'
              onChangeText = {(text) => this.setState ({text})}
              />
            <TextInput
              style={styles.inputBox}
              placeholder = 'new password'
              secureTextEntry = {true}
              maxLength = {16}
              onChangeText = {(text) => this.setState ({text})}
              />
            <TextInput
              style={styles.inputBox}
              placeholder = 'user.currentPassword'
              secureTextEntry = {true}
              maxLength = {16}
              onChangeText = {(text) => this.setState ({text})}
              />
          <Text style ={{padding: 0, fontSize: 42}}></Text>
        </View>

        <View style={{flex:1}}>
            <TouchableOpacity onPress={this.onButtonPress} style={styles.button}>
              <Text style={styles.buttonText}>Save Changes</Text>
            </TouchableOpacity>
        </View>
      </View>
    )
  }
}

const styles = StyleSheet.create({
  container : {
    backgroundColor: '#4295cb',
    flexGrow: 1,
    alignItems: 'center',
    flex:1
  },
  secondContainer: {
    marginTop: 50
  },
  inputBox : {
    marginTop: 10,
    width:200,
    height: 45,
    backgroundColor:'rgba(255, 255, 255, 0.6)',
    borderRadius: 25,
    paddingHorizontal: 16,
    fontSize: 16,
    marginVertical: 10,
    textAlign: 'center'
  },
  button: {
      alignItems: 'center',
      paddingTop: 10,
      paddingBottom: 10,
      width: 130,
      height: 40,
      backgroundColor:'#0D82CB',
      borderRadius: 25,
      marginVertical: 10,
      paddingVertical: 12
  },
  buttonText : {
    fontSize: 16,
    fontWeight: '500',
    textAlign: 'center',
    color: "#FFFFFF",
  }
});
