import React from 'react';
import {
  StyleSheet,
  View,
  StatusBar,
  Text,
  TextInput,
  Button,
  Alert

} from 'react-native';

//to navigate multiple pages

export default class Settings extends React.Component {
	onButtonPress(){
		Alert.alert("hi")
	}
	constructor(props) {
		super(props);
		this.state = {text: ''};
	}

  render() {
    return (
      <View style={styles.container}>
		<Text style = {{fontSize: 30, marginTop: 40}}>Settings</Text>
	    		<TextInput
	    			style={{marginTop: 30, textAlign:'center',height: 40, width: 200, borderColor: 'gray', borderWidth: 1,marginBottom:10}}
	    			placeholder = 'user.username'
	    			onChangeText = {(text) => this.setState ({text})}
	    			/>
	    		<TextInput
	    			style={{textAlign:'center',height: 40, width: 200, borderColor: 'gray', borderWidth: 1,marginBottom:10}}
	    			placeholder = 'new password'
	    			secureTextEntry = 'true'
	    			maxLength = '16'
	    			onChangeText = {(text) => this.setState ({text})}
	    			/>
	    		<TextInput
	    			style={{marginTop: 40, textAlign:'center',height: 40, width: 200, borderColor: 'gray', borderWidth: 1,marginBottom:10}}
	    			placeholder = 'user.currentPassword'
	    			secureTextEntry = 'true'
	    			maxLength = '16'
	    			onChangeText = {(text) => this.setState ({text})}
	    			/>
	    		<Text style ={{padding: 0, fontSize: 42}}>

	    		</Text>
			<View style={{flex:1}}>=
                  <Button 
                    onPress={()=> {this.onButtonPress()}}
                    title='Save Changes'
                    style={{height:40,backgroundColor:'#1e90ff'}}/>         
            </View >  
      </View>
    )
  }
}

const styles = StyleSheet.create({
  container : {
    backgroundColor: 'rgb(255, 255, 255)',
    flexGrow: 1,
    alignItems: 'center',
    flex:1
  }
});
