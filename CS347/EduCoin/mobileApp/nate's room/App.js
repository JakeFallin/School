import React from 'react';
import { StyleSheet, Text, View, TextInput } from 'react-native';

export default class App extends React.Component {
	constructor(props) {
		super(props);
		this.state = {text: ''};
	}
  	render() {
   		return (
	    	<View style = {{padding: 10, flex: 1, alignItems: 'center'}}>
	    		<Text style = {{fontSize: 50, color: 'red', marginTop: 30}} >
	    			Pizza Translator
	    		</Text>
	    		<TextInput
	    			style = {{marginTop: 80, fontSize: 20}}
	    			placeholder = 'Type here to translate...'
	    			onChangeText = {(text) => this.setState ({text})}
	    			/>
	    		<Text style ={{padding: 10, fontSize: 42, marginTop: 20}}>
	    		{this.state.text.split(' ').map((word) => word && '🍕').join(' ')}
	    		</Text>
	    	</View>
	    );
  	}
}