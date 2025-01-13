pipeline {
    agent any
    
    environment {
        PATH = "/usr/bin:/bin:/usr/sbin:/sbin"
    }
    
    stages {
        stage('Checkout') {
            steps {
                // Pull the code from the Git repository
                git branch: 'main', url: 'https://github.com/gounthar/calculate-pi.git'
            }
        }

        stage('Check Environment') {
            steps {
                sh '''
                    echo "PATH: $PATH"
                    which make
                    make --version
                   '''
            }
        }
        
        stage('Build') {
            steps {
                // Compile the C program using Makefile
                sh 'make'
            }
        }

        stage('Test') {
            steps {
                // Run the program with a sample input
                sh './pi_calculator 20'
            }
        }

        stage('Clean') {
            steps {
                // Clean up build artifacts
                sh 'make clean'
            }
        }
    }

    post {
        success {
            echo 'Pipeline completed successfully!'
        }
        failure {
            echo 'Pipeline failed. Check the logs for details.'
        }
    }
}

